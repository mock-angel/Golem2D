/*
 * Transform.h
 *
 *  Created on: 27-Jun-2020
 *      Author: anantha
 */

#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include <glm/gtx/quaternion.hpp>

#include "../../Component.h"
#include "../../Core/Math/Vector2.h"
#include "../../GLM.h"

#include SCRIPT_HEADERS

namespace Golem {

class Node;

class Transform: public Component {
    GAME_SCRIPT(Transform)

public:
    Vector3 position = Vector3(0, 0, 0);
    Vector3 scale = Vector3(1.5, 1, 1);
    Vector3 rotation = Vector3(glm::radians(0.f), 0, 0);

    glm::mat4 getModelMatrix(){
        calculateModelMatrix();
        return model;
    }

    virtual ~Transform();
private:

    glm::mat4 model = glm::mat4(1);

    void calculateModelMatrix(){
        model = glm::mat4(1);
        glm::quat quaternion = glm::quat(glm::vec3(rotation.x, rotation.y, rotation.z));

        glm::mat4 translationMatrix = glm::translate(glm::mat4(1), glm::vec3(position.x, position.y, position.z));;
        glm::mat4 rotationMatrix = glm::toMat4(quaternion);
        glm::mat4 scaleMatrix = glm::scale(glm::mat4(1), glm::vec3(scale.x, scale.y, scale.z));

        //model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        model = translationMatrix * rotationMatrix * scaleMatrix;
    }
};

} /* namespace Golem */

#endif /* TRANSFORM_H_ */
