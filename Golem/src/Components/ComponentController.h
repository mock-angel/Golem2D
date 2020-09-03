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

#include "../Component.h"

namespace Golem {

class ComponentController {

    //ComponentLayerSorter componentLayerSorter;

public:
    ComponentController();
    virtual ~ComponentController();

    std::list<std::shared_ptr<Component>> m_allComponents;

    void updateComponents();
    void renderComponents();

    void add(std::shared_ptr<Component>* component);
};

} /* namespace Golem */

#endif /* COMPONENTS_COMPONENTCONTROLLER_H_ */
