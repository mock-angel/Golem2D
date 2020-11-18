/*
 * ComponentController.h
 *
 *  Created on: 30-Aug-2020
 *      Author: anantha
 */

#ifndef COMPONENTS_COMPONENTCONTROLLER_H_
#define COMPONENTS_COMPONENTCONTROLLER_H_

#include <list>
#include <memory>
#include <map>

#include "../Component.h"
#include "SortingLayerEnum.h"

namespace Golem {



class ComponentController {

    //ComponentLayerSorter componentLayerSorter;
    bool m_changed = false;
public:
    ComponentController();
    virtual ~ComponentController();

    std::list<std::shared_ptr<Component>> m_allComponents;

    std::map<int, std::list<std::weak_ptr<Component>>> m_renderable;

    const std::list<SortingLayer> renderOrder = {
            SortingLayer::Layer0,
            SortingLayer::Layer1,
            SortingLayer::Layer2,
            SortingLayer::Layer3,
            SortingLayer::Layer4,
            SortingLayer::Layer5,
            SortingLayer::Layer6,
            SortingLayer::Layer7,
            SortingLayer::Layer8,
            SortingLayer::Layer9,
            SortingLayer::Layer10,
            SortingLayer::Layer11,
            SortingLayer::Layer12
    };

    /* Component Render. */
    void sortRenderable();
    void clearAllLayers();
    void renderAll();

    void updateComponents();
    void renderComponents();


    void add(std::shared_ptr<Component> component);
};

} /* namespace Golem */

#endif /* COMPONENTS_COMPONENTCONTROLLER_H_ */
