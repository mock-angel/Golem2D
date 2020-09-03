/*
 * Transform3d.h
 *
 *  Created on: 19-Aug-2020
 *      Author: anantha
 */

#ifndef TRANSFORM3D_H_
#define TRANSFORM3D_H_

#include "Math/Vector3.h"

namespace Golem {

class Node;

class Transform3d {
public:
    Vector3 position = Vector3(0, 0, 0);
    Vector3 scale = Vector3(0, 0, 0);
    //Quaternion rotation;

    Transform3d();
    virtual ~Transform3d();
};

} /* namespace Golem */

#endif /* TRANSFORM3D_H_ */
