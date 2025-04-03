//
// Contributors: Alfie
//

#ifndef VECTOR_H
#define VECTOR_H
#include <cstdint>

enum Axis
{
    x,
    y,
    z,
    w
};


template <typename T, uint32_t n>
class Vector
{
public:
    [[nodiscard]] T& operator[] (int i) { return values[i]; }
    [[nodiscard]] T& operator[] (Axis coord) { return values[coord]; }

    T* get_data() { return values; }

protected:
    Vector() = default;

    void fill(T values[n]) { for (int i = 0; i < n; i++) this->values[i] = values[i]; }

    T values[n];
};


template <typename T>
class Vector2 : public Vector<T, 2>
{
public:
    Vector2() : Vector<T, 2>() { }
    Vector2(T x, T y)
    {
        T values[] = { x, y };
        this->fill(values);
    }
};


template <typename T>
class Vector3 : public Vector<T, 3>
{
public:
    Vector3() : Vector<T, 3>() { }
    Vector3(T x, T y, T z)
    {
        T values[] = { x, y, z };
        this->fill(values);
    }
};


template <typename T>
class Vector4 : public Vector<T, 4>
{
public:
    Vector4() : Vector<T, 4>() { }
    Vector4(T x, T y, T z, T w)
    {
        T values[] = { x, y, z, w };
        this->fill(values);
    }
};

#endif //VECTOR_H
