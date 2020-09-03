/*
 * Component.cpp
 *
 *  Created on: 18-Aug-2020
 *      Author: anantha
 */

#include "Node.h"
#include "Component.h"

namespace Golem {

Component::Component() {
    // TODO Auto-generated constructor stub

}

Component::~Component() {
    // TODO Auto-generated destructor stub
}

void Component::attatchNode(Node* node){
    gameNode = node;
}

void Component::enableUpdates(bool value){
    renderComponent = value;
}

void Component::enableRenders(bool value){
    updateComponent = value;
}

void Component::render(){

}

void Component::update(){

}

Node* Component::getGameObject(){
    return gameNode;
}



} /* namespace Golem */
