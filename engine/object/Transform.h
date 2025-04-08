//
// Contributors: Alfie
//

#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "../core/Quaternion.h"
#include "../core/Vector.h"

class Transform
{
public:
    explicit Transform(
        Vector3<float> const& displacement = Vector3<float>(),
        Quaternion const& orientation = Quaternion(),
        Vector3<float> const& scale = Vector3<float>(1.0f, 1.0f, 1.0f))
        : displacement(displacement), orientation(orientation), scale(scale) { }

    [[nodiscard]] Vector3<float> const& get_displacement() const { return displacement; }
    [[nodiscard]] Quaternion const& get_orientation() const { return orientation; }
    [[nodiscard]] Vector3<float> const& get_scale() const { return scale;}

    void set_displacement(const Vector3<float>& displacement) { this->displacement = displacement; }
    void set_orientation(Quaternion const& orientation) { this->orientation = orientation; }
    void set_scale(Vector3<float> const& scale) { this->scale = scale; }

protected:
    Vector3<float> displacement;
    Quaternion orientation;
    Vector3<float> scale;
};

#endif //TRANSFORM_H
