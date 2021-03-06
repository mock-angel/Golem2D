/*
 * RenderLayer.h
 *
 *  Created on: 24-Aug-2020
 *      Author: anantha
 */

#ifndef LAYERS_RENDERLAYER_H_
#define LAYERS_RENDERLAYER_H_

#include <string>
#include <vector>
#include <memory>

#include "../ComponentRenderer.h"
#include "RenderLayerEnum.h"

namespace Golem {

class ComponentRenderer;

class RenderLayer {
    std::string sortingLayerName;

    RenderLayerEnum sortingLayer = Layer0;

    std::vector<std::shared_ptr<ComponentRenderer>> drawable;

public:
    RenderLayer();
    virtual ~RenderLayer();

    void sort();
};

} /* namespace Golem */

#endif /* LAYERS_RENDERLAYER_H_ */
