//
// Contributors: Alfie
//

#ifndef QUATERNION_H
#define QUATERNION_H
#include "Vector.h"

class Quaternion : protected Vector<float, 4>
{
public:
    Quaternion() : Vector(0.0f, 0.0f, 0.0f, 1.0f) { }
    Quaternion(float const x, float const y, float const z, float const w) : Vector(x, y, z, w) { }
    explicit Quaternion(Vector const& vec) : Vector(vec) { }

    [[nodiscard]]
    float operator[](int const i) const { return values[i]; }
    [[nodiscard]]
    float operator[](Axis const coord) const { return values[coord]; }

    Quaternion operator*(Quaternion const& quat) const;
    Vector3<float> operator*(Vector3<float> const& vec) const;

    [[nodiscard]] Quaternion get_conjugate() const { return { -(*this)[x], -(*this)[y], -(*this)[z], (*this)[w] }; }
};


inline Quaternion Quaternion::operator*(Quaternion const &quat) const
{
    Quaternion const& a = *this;
    Quaternion const& b = quat;

    return {
        (a[x] * b[w]) + (a[w] * b[x]) + (a[y] * b[z]) - (a[z] * b[y]),
        (a[y] * b[w]) + (a[w] * b[y]) + (a[z] * b[x]) - (a[x] * b[z]),
        (a[z] * b[w]) + (a[w] * b[z]) + (a[x] * b[y]) - (a[y] * b[x]),
        (a[w] * b[w]) - (a[x] * b[x]) - (a[y] * b[y]) - (a[z] * b[y])
    };
}


inline Vector3<float> Quaternion::operator*(Vector3<float> const &vec) const
{
    Quaternion quat = *this * Quaternion(vec[x], vec[y], vec[z], 0.0f) * get_conjugate();
    return Vector3<float>(quat[x], quat[y], quat[z]);
}


#endif //QUATERNION_H
