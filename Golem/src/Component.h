/*
 * Component.h
 *
 *  Created on: 18-Aug-2020
 *      Author: anantha
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

namespace Golem {

class Node;

class Component {
    Node* gameNode = nullptr;

    bool updateComponent = true;
    bool renderComponent = false;

    void attatchNode(Node* node);//TODO: Revise method.

    friend class Node;
public:

    bool isUpdatable(){return updateComponent;}
    bool isRenderable(){return renderComponent;}

    void enableUpdates(bool value);
    void enableRenders(bool value);

    Node* getGameObject();

    virtual void render();
    virtual void update();

    Component();
    virtual ~Component();
};

} /* namespace Golem */

#endif /* COMPONENT_H_ */
