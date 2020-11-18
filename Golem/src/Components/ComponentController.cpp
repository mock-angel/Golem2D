/*
 * ComponentController.cpp
 *
 *  Created on: 30-Aug-2020
 *      Author: anantha
 */

#include "ComponentController.h"

#include <memory>
#include <string>

#include "../Node.h"
#include "../Debug.h"

namespace Golem {

ComponentController::ComponentController() {
    // TODO Auto-generated constructor stub
    for(int i = 0; i < 14; i++){
        //m_renderable.insert({i, std::list<std::shared_ptr<Component>>});
        //m_renderable.insert({i, std::list<std::shared_ptr<Component>>()});
        m_renderable[i] = std::list<std::weak_ptr<Component>>();
    }
}

ComponentController::~ComponentController() {
    // TODO Auto-generated destructor stub
}

void ComponentController::updateComponents(){
    // U
    Component* component = nullptr;
    for(std::shared_ptr<Component> &component_ptr : m_allComponents) {
        component = component_ptr.get();

        if(component->isUpdatable()) component->update();
    }
}

void ComponentController::clearAllLayers(){
    // U
    for(auto &r_pair: m_renderable)
        //Node::print(std::string(std::to_string(r_pair.first)));
        r_pair.second.clear();

}

void ComponentController::sortRenderable(){
    //Debug::log("Components count::"+std::to_string(m_allComponents.size()));

    for(std::shared_ptr<Component> component_ptr : m_allComponents){

        //Node::print("Component validity :"+ std::to_string(component_ptr || 0));
        if(component_ptr->isRenderable()) {
            m_renderable[component_ptr->sortingLayer].push_back(component_ptr);
            //Debug::log(std::to_string(component_ptr->sortingLayer) + std::string(" :: layer sorted to..."));
        }
        else; //Debug::log("Component Sorter:: Not sorted to any render layer");
    }
}

void ComponentController::renderAll(){
    for(const SortingLayer& renderLayerValue: renderOrder){
        for(std::weak_ptr<Component> comp: m_renderable[renderLayerValue]){

            comp.lock()->render();

        }
    }
}

void ComponentController::renderComponents(){

    //Debug::log("ComponentController::Render():: ");
    if(m_changed){
        clearAllLayers();
        sortRenderable();
    }
    renderAll();
}

void ComponentController::add(std::shared_ptr<Component> component){

    m_allComponents.push_back(component);
    component->Start();

    m_changed = true;
}

} /* namespace Golem */
