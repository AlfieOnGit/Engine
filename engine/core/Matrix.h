//
// Contributors: Alfie
//

#ifndef MATRIX_H
#define MATRIX_H
#include <cstdint>

#include "Quaternion.h"
#include "Vector.h"

template <typename T, uint8_t n, uint8_t m>
class Matrix : protected Vector<Vector<T, m>, n>
{
public:
    explicit Matrix(const bool is_identity = true)
    {
        if (is_identity && m == n) for (int i = 0; i < n; i++) (*this)[i][i] = T(1);
    }

    Matrix(Matrix const& mat) { *this = mat; }

    Matrix& operator=(Matrix const& mat)
    {
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) (*this)[i][j] = mat[i][j];
        return *this;
    }

    [[nodiscard]] Vector<T, m> operator[](int const i) const { return this->values[i]; }
    [[nodiscard]] Vector<T, m>& operator[](int const i) { return this->values[i]; }

    [[nodiscard]] Matrix operator+(Matrix const& target) const { return Matrix(this->Vector<Vector<T, m>, n>::operator+(target)); }
    [[nodiscard]] Matrix operator-(Matrix const& target) const { return Matrix(this->Vector<Vector<T, m>, n>::operator-(target)); }
    [[nodiscard]] Matrix operator*(Matrix const& target) const;
    [[nodiscard]] Vector<T, n> operator*(Vector<T, n> const& vec) const;

    Matrix& operator+=(Matrix const& target) { return *this = *this + target; }
    Matrix& operator-=(Matrix const& target) { return *this = *this - target; }
    Matrix& operator*=(Matrix const& target) { return *this = *this * target; }

    T* get_array() { return this->values[0].get_array(); }

    void print() const;

private:
    explicit Matrix(Vector<Vector<T, m>, n> vec) { for (int i = 0; i < n; i++) this->values[i] = vec[i]; }
};


template<typename T, uint8_t n, uint8_t m>
Matrix<T, n, m> Matrix<T, n, m>::operator*(Matrix const &target) const
{
    Matrix out = Matrix(false);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        for (int k = 0; k < n; k++) out.values[i][j] += (*this)[k][j] * target[i][k];
    return out;
}


template<typename T, uint8_t n, uint8_t m>
Vector<T, n> Matrix<T, n, m>::operator*(Vector<T, n> const& vec) const
{
    auto out = Vector<T, n>();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) out[j] += vec[i] * (*this)[i][j];
    return out;
}


template<typename T, uint8_t n, uint8_t m>
void Matrix<T, n, m>::print() const
{
    std::cout << "[MATRIX]\n";
    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
        {
            std::cout << this->values[x][y] << ' ';
        }
        std::cout << '\n';
    }
}


namespace Matrices
{
    template <typename T>
    Matrix<T, 4, 4> orthographic(Vector<T, 3> const& min, Vector<T, 3> const& max)
    {
        Matrix<T, 4, 4> out;

        for (int i = 0; i < 3; i++)
        {
            out[i][i] = 2 / (max[i] - min[i]);
            out[3][i] = -(max[i] + min[i]) / (max[i] - min[i]);
        }
        out[2][2] *= -1;

        return out;
    }


    template <typename T>
    Matrix<T, 4, 4> perspective(T near_z, T far_z, T fov, T aspect)
    {
        Matrix<T, 4, 4> out;

        T const f = 1 / tan(fov / 2);

        out[0][0] = f / aspect;
        out[1][1] = f;
        out[2][2] = (near_z + far_z) / (near_z - far_z);
        out[2][3] = -1;
        out[3][2] = (2 * near_z * far_z) / (near_z - far_z);

        return out;
    }


    inline Matrix<float, 4, 4> rotation(Quaternion const& quat)
    {
        Matrix<float, 4, 4> out;

        out[0][0] = 1 - 2 * (quat[y] * quat[y] + quat[z] * quat[z]);
        out[0][1] = 2 * (quat[x] * quat[y] + quat[z] * quat[w]);
        out[0][2] = 2 * (quat[x] * quat[z] - quat[y] * quat[w]);

        out[1][0] = 2 * (quat[x] * quat[y] - quat[z] * quat[w]);
        out[1][1] = 1 - 2 * (quat[x] * quat[x] + quat[z] * quat[z]);
        out[1][2] = 2 * (quat[y] * quat[z] + quat[x] * quat[w]);

        out[2][0] = 2 * (quat[x] * quat[z] + quat[y] * quat[w]);
        out[2][1] = 2 * (quat[y] * quat[z] - quat[x] * quat[w]);
        out[2][2] = 1 - 2 * (quat[x] * quat[x] + quat[y] * quat[y]);

        return out;
    }

    template <typename T>
    Matrix<T, 4, 4> rotation(T const radians, Vector3<T> const& axis)
    {
        Matrix<T, 4, 4> out;

        float const c = cos(radians);
        float const s = sin(radians);
        float const omc = 1 - c;

        out[0][0] = axis[x] * axis[x] * omc + c;
        out[0][1] = axis[x] * axis[y] * omc + axis[z] * s;
        out[0][2] = axis[x] * axis[z] * omc - axis[y] * s;

        out[1][0] = axis[y] * axis[x] * omc - axis[z] * s;
        out[1][1] = axis[y] * axis[y] * omc + c;
        out[1][2] = axis[y] * axis[z] * omc + axis[x] * s;

        out[2][0] = axis[z] * axis[x] * omc + axis[y] * s;
        out[2][1] = axis[z] * axis[y] * omc - axis[x] * s;
        out[2][2] = axis[z] * axis[z] * omc + c;

        return out;
    }


    template <typename T>
    Matrix<T, 4, 4> scale(Vector<T, 3> const& vec)
    {
        Matrix<T, 4, 4> out;
        for (int i = 0; i < 3; i++) out[i][i] = vec[i];
        return out;
    }


    template <typename T>
    Matrix<T, 4, 4> translation(Vector<T, 3> const& vec)
    {
        Matrix<T, 4, 4> out;
        for (int i = 0; i < 3; i++) out[3][i] = vec[i];
        return out;
    }
}

#endif //MATRIX_H
