/*
 * LayerManager.h
 *
 *  Created on: 24-Aug-2020
 *      Author: anantha
 */

#ifndef GRAPHICS_LAYERS_RENDERLAYERMANAGER_H_
#define GRAPHICS_LAYERS_RENDERLAYERMANAGER_H_

#include <map>
#include <vector>

#include "RenderLayer.h"

namespace Golem {



class RenderLayerManager {
    //Pass the shared_ptr by reference.
    std::map<RenderLayerEnum, RenderLayer> drawables;

public:
    RenderLayerManager();
    virtual ~RenderLayerManager();

    void sort();
};

} /* namespace Golem */

#endif /* GRAPHICS_LAYERS_RENDERLAYERMANAGER_H_ */
