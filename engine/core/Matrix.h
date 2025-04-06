//
// Contributors: Alfie
//

#ifndef MATRIX_H
#define MATRIX_H
#include <cstdint>

#include "Vector.h"

template <typename T, uint8_t n, uint8_t m>
class Matrix : protected Vector<Vector<T, m>, n>
{
public:
    Matrix() = default;

    Matrix(Matrix const& mat) { *this = mat; }

    Matrix& operator=(Matrix const& mat)
    {
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) this->values[i][j] = mat.values[i][j];
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

private:
    explicit Matrix(Vector<Vector<T, m>, n> vec) { for (int i = 0; i < n; i++) this->values[i] = vec[i]; }
};


template<typename T, uint8_t n, uint8_t m>
Matrix<T, n, m> Matrix<T, n, m>::operator*(Matrix const &target) const
{
    Matrix out = Matrix();
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        for (int k = 0; k < n; k++) out.values[i][j] += (*this)[k][j] * target[i][k];
    return out;
}


template<typename T, uint8_t n, uint8_t m>
Vector<T, n> Matrix<T, n, m>::operator*(Vector<T, n> const& vec) const
{
    auto out = Vector<T, n>();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) out[i] += vec[i] * (*this)[i][j];
    return out;
}


namespace Matrices
{
    template <typename T, uint8_t n>
    Matrix<T, n, n> get_identity()
    {
        Matrix<T, n, n> out;
        for (int i = 0; i < n; i++) out[i][i] = T(1);
        return out;
    }
}

#endif //MATRIX_H
