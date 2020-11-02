/*
 * Vector2.h
 *
 *  Created on: 11-Aug-2020
 *      Author: anantha
 */

#ifndef CORE_MATH_VECTOR3_H_
#define CORE_MATH_VECTOR3_H_

#include "Vector2.h"

namespace Golem {

class Vector2;
class Transform;

class Vector3 {
    float x = 0, y = 0, z = 0;

public:
    friend class Transform;

    Vector3();
    Vector3(float t_x, float t_y, float t_z);
    //constexpr Vector3(const Golem::Vector3&);

    float getX() const;
    float getY() const;
    float getZ() const;

    Vector3& operator = (const Vector3 &V );
    Vector3& operator = (const Vector2 &V );

    virtual ~Vector3();
};

} /* namespace Golem */

#endif /* MATH_VECTOR2_H_ */
