/*
 * Camera.cpp
 *
 *  Created on: 18-Oct-2020
 *      Author: anantha
 */

#include "Camera.h"

namespace Golem {

Camera::Camera() {
    // TODO Auto-generated constructor stub

}

Camera::~Camera() {
    // TODO Auto-generated destructor stub
}

glm::mat4 Camera::getClipMatrix(){

    calculateProjection();

    //model = glm::mat4(1.0f);
    //model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

    return proj*view;
}

glm::mat4 Camera::getProjMatrix(){
    return proj;
}

glm::mat4 Camera::getViewMatrix(){
    view = glm::mat4(1.0f);
    view = glm::translate(view, cameraPos);

    return view;
}

void Camera::calculateProjection(){
    if(!projectionFlag) return;

    if(perspective)
        proj = glm::perspective(glm::radians(fovy), width / height, nearPlane, farPlane);
    projectionFlag = false;
}

void Camera::setWidth(float t_width)
{
    width = t_width;
    projectionFlag = true;
}

void Camera::setHeight(float t_height)
{
    height = t_height;
    projectionFlag = true;
}

void Camera::setFov(float t_fovy)
{
    fovy = t_fovy;
    projectionFlag = true;
}

void Camera::setNearPlane(float t_nearz)
{
    nearPlane = t_nearz;
    projectionFlag = true;
}

void Camera::setFarPlane(float t_farz)
{
    farPlane = t_farz;
    projectionFlag = true;
}

} /* namespace Golem */
