/*
 * Vector2.h
 *
 *  Created on: 11-Aug-2020
 *      Author: anantha
 */

#ifndef CORE_MATH_VECTOR2_H_
#define CORE_MATH_VECTOR2_H_

#include "Vector3.h"

namespace Golem {

class Vector3;

class Vector2 {
    float x = 0, y = 0;

public:
    Vector2(float t_x, float t_y);

    float getX() const;
    float getY() const;

    Vector2& operator = (const Vector2 &V );
    Vector2& operator = (const Vector3 &V );

    float Magnitude();
    Vector2 Divide(float num);
    Vector2 Normalized();

    virtual ~Vector2();
};

} /* namespace Golem */

#endif /* CORE_MATH_VECTOR2_H_ */
