/*
 * Transform.h
 *
 *  Created on: 27-Jun-2020
 *      Author: anantha
 */

#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include "Math/Vector2.h"

namespace Golem {

class Node;

class Transform {
public:
    Vector2 position = Vector2(0, 0);
    Vector2 scale = Vector2(0, 0);
    float rotation = 0;

    Transform();
    virtual ~Transform();
};

} /* namespace Golem */

#endif /* TRANSFORM_H_ */
