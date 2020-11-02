/*
 * Camera.h
 *
 *  Created on: 18-Oct-2020
 *      Author: anantha
 */

#ifndef GRAPHICS_CAMERA_CAMERA_H_
#define GRAPHICS_CAMERA_CAMERA_H_

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL2/SDL_opengl.h>

#include "../../GLM.h"

namespace Golem {

class Camera {
public:
    Camera();
    virtual ~Camera();

    void calculateProjection();
    void calculateViewMatrix();

    void setWidth(float t_width);
    void setHeight(float t_height);
    void setFov(float t_fovy);
    void setNearPlane(float t_nearz);
    void setFarPlane(float t_farz);

    glm::mat4 getClipMatrix();
    glm::mat4 getProjMatrix();
    glm::mat4 getModelMatrix();
    glm::mat4 getViewMatrix();

private:
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, -3.0f);
    glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
    //glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);


    bool perspective = true;
    float width = 1920.0f;
    float height = 1080.0f;
    float nearPlane = 0.1f;
    float farPlane = 100.0f;
    float fovy = 45.0f;

    bool projectionFlag = true;

    glm::mat4 proj = glm::mat4(1.0f);
    //glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);

};

} /* namespace Golem */

#endif /* GRAPHICS_CAMERA_CAMERA_H_ */
