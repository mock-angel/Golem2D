/*
 * LayerManager.h
 *
 *  Created on: 24-Aug-2020
 *      Author: anantha
 */

#ifndef LAYERS_LAYERMANAGER_H_
#define LAYERS_LAYERMANAGER_H_

#include <map>
#include <vector>

#include "RenderLayer.h"

namespace Golem {



class LayerManager {
    //Pass the shared_ptr by reference.
    std::map<RenderLayerEnum, RenderLayer> drawables;

public:
    LayerManager();
    virtual ~LayerManager();

    void sort();
};

} /* namespace Golem */

#endif /* LAYERS_LAYERMANAGER_H_ */
