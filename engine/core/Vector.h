//
// Contributors: Alfie
//

#ifndef VECTOR_H
#define VECTOR_H

#include <cstdint>
#include <type_traits>

#include "Axis.h"

template <typename T, uint8_t n>
class Vector
{
public:
    Vector() { for (int i = 0; i < n; i++) values[i] = T(); }

    template <typename... Ts>
    requires (sizeof...(Ts) == n && ((std::is_same_v<T, Ts>), ...))
    explicit Vector(Ts... values) {
        int index = 0;
        ((this->values[index++] = values), ...);
    }

    Vector(Vector const& vec) { *this = vec; }

    [[nodiscard]]
    T operator[](int const i) const { return values[i]; }
    [[nodiscard]]
    T& operator[](int const i) { return values[i]; }
    [[nodiscard]]
    T operator[](Axis const coord) const { return values[coord]; }
    [[nodiscard]]
    T& operator[](Axis const coord) { return values[coord]; }

    Vector& operator=(Vector const& vec)
    {
        for (int i = 0; i < n; i++) (*this)[i] = vec[i];
        return *this;
    }

    Vector operator-() const {
        Vector out;
        for (int i = 0; i < n; i++) out[i] = -this->values[i];
        return out;
    }

    Vector operator+(Vector const& target) const {
        Vector out;
        for (int i = 0; i < n; i++) out[i] = this->values[i] + target[i];
        return out;
    }

    Vector operator-(Vector const& target) const {
        Vector out;
        for (int i = 0; i < n; i++) out[i] = this->values[i] - target[i];
        return out;
    }

    Vector operator*(Vector const& target) const
    {
        Vector out;
        for (int i = 0; i < n; i++) out[i] = this->values[i] * target[i];
        return out;
    }

    Vector operator/(Vector const& target) const
    {
        Vector out;
        for (int i = 0; i < n; i++) out[i] = this->values[i] / target[i];
        return out;
    }

    Vector& operator+=(Vector const& target) { return this = this + target; }
    Vector& operator-=(Vector const& target) { return this = this - target; }
    Vector& operator*=(Vector const& target) { return this = this * target; }
    Vector& operator/=(Vector const& target) { return this = this / target; }

    Vector<T, n + 1> operator<<(T target)
    {
        Vector<T, n + 1> out;
        for (int i = 0; i < n; i++) out[i] = (*this)[i];
        out[n] = target;
        return out;
    }

    T* get_array() { return values; }

    void print() const;

protected:
    T values[n];
};

template <typename T, uint8_t n>
void Vector<T, n>::print() const
{
    std::cout << "[VECTOR]\n";
    for (int i = 0; i < n; i++) std::cout << values[i] << ' ';
    std::cout << '\n';
}


template <typename T>
using Vector2 = Vector<T, 2>;

template <typename T>
using Vector3 = Vector<T, 3>;

template <typename T>
using Vector4 = Vector<T, 4>;


namespace Vectors
{
    template <typename T, uint8_t n>
    Vector<T, n> axis(Axis const axis)
    {
        Vector<T, n> out;
        out[axis] = T(1);
        return out;
    }
}

#endif //VECTOR_H
