/*
 * Vector2.cpp
 *
 *  Created on: 11-Aug-2020
 *      Author: anantha
 */

#include "Vector3.h"

#include "Vector2.h"

namespace Golem {

Vector3::Vector3(float t_x, float t_y, float t_z) {
    x = t_x;
    y = t_y;
    z = t_z;
    // TODO Auto-generated constructor stub
}

float Vector3::getX() const{
    return x;
}

float Vector3::getY() const{
    return y;
}

float Vector3::getZ() const{
    return z;
}

Vector3::~Vector3() {
    // TODO Auto-generated destructor stub
}

Vector3& Vector3::operator = (const Vector3 &V ){
    if (this == &V) return *this;

    x = V.x;
    y = V.y;
    z = V.z;

    return *this;
}

Vector3& Vector3::operator = (const Vector2 &V ) {

    x = V.getX();
    y = V.getY();
    z = 0;
    return *this;
}

} /* namespace Golem */
