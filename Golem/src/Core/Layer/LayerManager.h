/*
 * LayerManager.h
 *
 *  Created on: 12-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_LAYER_LAYERMANAGER_H_
#define CORE_LAYER_LAYERMANAGER_H_

#include <memory>
#include <list>

#include "Layer.h"

namespace Golem {

class Event;

class LayerManager {
public:
    LayerManager();
    virtual ~LayerManager();

    void update(){
        for(std::shared_ptr<Layer>& layer: m_updateLayers) layer->update();
    }

    inline void render(){
        for(std::shared_ptr<Layer>& layer: m_renderLayers) layer->update();
    }
    inline void onEvent(Event& event){
        for(std::shared_ptr<Layer>& layer: m_renderLayers) layer->onEvent(event);
    }

    void attachLayer(std::shared_ptr<Layer> t_layer);
    void detachLayer(std::shared_ptr<Layer> t_layer){
        m_allLayers.remove(t_layer);
        m_updateLayers.remove(t_layer);
        m_renderLayers.remove(t_layer);
        m_eventLayers.remove(t_layer);
    }

    std::list<std::shared_ptr<Layer>> m_allLayers;
    std::list<std::shared_ptr<Layer>> m_updateLayers;
    std::list<std::shared_ptr<Layer>> m_renderLayers;
    std::list<std::shared_ptr<Layer>> m_eventLayers;

};

} /* namespace Golem */

#endif /* CORE_LAYER_LAYERMANAGER_H_ */
