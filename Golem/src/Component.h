/*
 * Component.h
 *
 *  Created on: 18-Aug-2020
 *      Author: anantha
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <memory>
#include <type_traits>

#include "Components/Renderable.h"

namespace Golem {

class Node;

class Component: public Renderable {
    std::weak_ptr<Node> parentNode;

    bool updateComponent = true;

    //void attatchNode(Node* node);//TODO: Revise method.

    friend class Node;

    void setOwner(std::weak_ptr<Node> t_node);
public:

    bool isUpdatable(){return updateComponent;}
    void enableUpdates(bool value);
    //void enableRenders(bool value){renderComponent = value};

    std::weak_ptr<Node> getGameObject();

    virtual void render() override;//TODO: Test if this override will cause any problem.
    virtual void update() ;



    Component();
    virtual ~Component();
};

} /* namespace Golem */

#endif /* COMPONENT_H_ */
