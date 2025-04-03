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

    [[nodiscard]] Vector<T, m> operator[](int const i) const { return this->values[i]; }
    [[nodiscard]] Vector<T, m>& operator[](int const i) { return this->values[i]; }

    [[nodiscard]] Matrix operator+(Matrix const& target) { return Matrix(this->Vector<Vector<T, m>, n>::operator+(target)); }
    [[nodiscard]] Matrix operator-(Matrix const& target) { return Matrix(this->Vector<Vector<T, m>, n>::operator-(target)); }
    [[nodiscard]] Matrix operator*(Matrix const& target) { return Matrix(this->Vector<Vector<T, m>, n>::operator*(target)); }
    [[nodiscard]] Matrix operator/(Matrix const& target) { return Matrix(this->Vector<Vector<T, m>, n>::operator/(target)); }

    Matrix& operator+=(Matrix const& target) { return *this = *this + target; }
    Matrix& operator-=(Matrix const& target) { return *this = *this - target; }
    Matrix& operator*=(Matrix const& target) { return *this = *this * target; }
    Matrix& operator/=(Matrix const& target) { return *this = *this / target; }

private:
    explicit Matrix(Vector<Vector<T, m>, n> vec) { for (int i = 0; i < n; i++) this->values[i] = vec[i]; }
};


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
