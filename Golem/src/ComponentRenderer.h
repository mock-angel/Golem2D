/*
 * ComponentRenderer.h
 *
 *  Created on: 24-Aug-2020
 *      Author: anantha
 */

#ifndef COMPONENTRENDERER_H_
#define COMPONENTRENDERER_H_

#include "Layers/RenderLayerEnum.h"
#include "Layers/RenderLayer.h"

namespace Golem {


class ComponentRenderer {

public:
    RenderLayerEnum sortingLayer;

    ComponentRenderer();
    virtual ~ComponentRenderer();

    virtual void render() = 0;
};

} /* namespace Golem */

#endif /* COMPONENTRENDERER_H_ */
