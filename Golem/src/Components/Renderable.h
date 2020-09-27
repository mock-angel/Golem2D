/*
 * Renderable.h
 *
 *  Created on: 24-Sep-2020
 *      Author: anantha
 */

#ifndef COMPONENTS_RENDERABLE_H_
#define COMPONENTS_RENDERABLE_H_

#include <memory>

#include "SortingLayerEnum.h"

namespace Golem {

class ComponentController;

class Renderable {
    bool renderComponent = false;

protected:
    std::weak_ptr<ComponentController> m_componentController;

public:
    Renderable();
    virtual ~Renderable();

    //SortingLayer getSortingLayer(){return sortingLayer;}
    //void setSortingLayer(SortingLayer t_sortingLayer){ sortingLayer = t_sortingLayer;}
    enum SortingLayer sortingLayer = SortingLayer::Layer0;

    void enableRenders(bool value);
    bool isRenderable(){return renderComponent;}


    virtual void render() = 0;
};

} /* namespace Golem */

#endif /* COMPONENTS_RENDERABLE_H_ */
