/*
 * Component.cpp
 *
 *  Created on: 18-Aug-2020
 *      Author: anantha
 */

#include "Component.h"

#include "Debug.h"

namespace Golem {

Component::Component() {
    // TODO Auto-generated constructor stub

}

Component::~Component() {
    // TODO Auto-generated destructor stub
}


void Component::enableUpdates(bool value){
    updateComponent = value;
}



void Component::render(){
    Debug::log("Component::render() executed");
}

void Component::update(){

}

std::weak_ptr<Node> Component::getGameObject(){
    return gameNode;
}



} /* namespace Golem */
