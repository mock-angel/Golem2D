/*
 * LayerManager.cpp
 *
 *  Created on: 12-Nov-2020
 *      Author: anantha
 */

#include "LayerManager.h"

#include "Game.h"


namespace Golem {

LayerManager::LayerManager() {
    // TODO Auto-generated constructor stub

}

LayerManager::~LayerManager() {
    // TODO Auto-generated destructor stub
}

void LayerManager::attachLayer(std::shared_ptr<Layer> t_layer){

    m_eventLayers.push_back(t_layer);
    if(t_layer->isUpdatable()) m_updateLayers.push_back(t_layer);
    if(t_layer->isRenderable()) m_renderLayers.push_back(t_layer);
    if(t_layer->isEventListener()) {
        Game::getEventBus().lock()->addListener(t_layer);
        m_eventLayers.push_back(t_layer);
    }
    t_layer->onAttach();

}

} /* namespace Golem */
