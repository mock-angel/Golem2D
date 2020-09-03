/*
 * ComponentController.cpp
 *
 *  Created on: 30-Aug-2020
 *      Author: anantha
 */

#include "ComponentController.h"

#include <memory>

namespace Golem {

ComponentController::ComponentController() {
    // TODO Auto-generated constructor stub

}

ComponentController::~ComponentController() {
    // TODO Auto-generated destructor stub
}

void ComponentController::updateComponents(){
    // U
    Component* component = nullptr;
    for(std::shared_ptr<Component> component_ptr : m_allComponents) {
        component = component_ptr.get();

        if(component->isUpdatable()) component->update();
    }
}

void ComponentController::renderComponents(){


}

void ComponentController::add(std::shared_ptr<Component>* component){
    // Make sure only the address of the shared_ptr
    // is passed To avoid duplication.
    m_allComponents.emplace_back(*component);

}

} /* namespace Golem */
