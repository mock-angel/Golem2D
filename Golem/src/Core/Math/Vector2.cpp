/*
 * Vector2.cpp
 *
 *  Created on: 11-Aug-2020
 *      Author: anantha
 */

#include "Vector2.h"

#include <math.h>

#include <iostream>

#include "Vector3.h"

using namespace std;

namespace Golem {

Vector2::Vector2(float t_x, float t_y) {
    x = t_x;
    y = t_y;
    // TODO Auto-generated constructor stub
}

float Vector2::getX() const{
    return x;
}

float Vector2::getY() const{
    return y;
}

Vector2::~Vector2() {
    // TODO Auto-generated destructor stub
}

Vector2& Vector2::operator = (const Vector2 &V ) {
    if (this == &V) return *this;

    x = V.x;
    y = V.y;

    return *this;
}

Vector2& Vector2::operator = (const Vector3 &V ) {

    x = V.getX();
    y = V.getY();

    return *this;
}

float Vector2::Magnitude(){
    return sqrt(x * x + y * y);
}

Vector2 Vector2::Divide(float num){
    return Vector2(x/num, y/num);
}

Vector2 Vector2::Normalized(){
    return Divide(Magnitude());
}

} /* namespace Golem */
