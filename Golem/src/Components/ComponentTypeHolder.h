/*
 * ComponentTypeHolder.h
 *
 *  Created on: 26-Oct-2020
 *      Author: anantha
 */

#ifndef COMPONENTS_COMPONENTTYPEHOLDER_H_
#define COMPONENTS_COMPONENTTYPEHOLDER_H_

#include "../Component.h"

namespace Golem {

class ComponentTypeHolder {
public:
    ComponentTypeHolder();
    virtual ~ComponentTypeHolder();

    template<typename T>
    static bool addScript(){
        return true;
    }
};

} /* namespace Golem */

#endif /* COMPONENTS_COMPONENTTYPEHOLDER_H_ */
