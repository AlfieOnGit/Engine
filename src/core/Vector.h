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
    Vector() = default;

    template <typename... Ts>
    requires (sizeof...(Ts) == n && ((std::is_same_v<T, Ts>), ...))
    explicit Vector(Ts... values) {
        int index = 0;
        ((this->values[index++] = values), ...);
    }

    [[nodiscard]]
    T operator[](int const i) const { return values[i]; }
    [[nodiscard]]
    T& operator[](int const i) { return values[i]; }
    [[nodiscard]]
    T operator[](Axis const coord) const { return values[coord]; }
    [[nodiscard]]
    T& operator[](Axis const coord) { return values[coord]; }

    Vector operator+(Vector const& target) const {
        Vector out;
        for (int i = 0; i < n; i++) out[i] = this->values[i] + target[i];
        return out;
    }

    Vector operator-() const {
        Vector out;
        for (int i = 0; i < n; i++) out[i] = -this[i];
        return out;
    }

    Vector operator-(Vector const& target) const {
        Vector out;
        for (int i = 0; i < n; i++) out[i] = this->values[i] - target[i];
        return out;
    }

    T* get_data() { return values; }

protected:
    T values[n];
};

template <typename T>
using Vector2 = Vector<T, 2>;

template <typename T>
using Vector3 = Vector<T, 3>;

template <typename T>
using Vector4 = Vector<T, 4>;

#endif //VECTOR_H
