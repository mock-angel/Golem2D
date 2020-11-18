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
#include "Res/Scripts/ComponentsAssembly.h"

namespace Golem {

#define SCRIPT_HEADERS "../../Components/ComponentTypeHolder.h"

// Defines what the adder script does.
#define STATIC_SCRIPT_ADDER_FUNCTION(ClassName) \
    static void scriptAdder(){ \
        ComponentTypeHolder::addScript<ClassName>();\
    }

#define GAME_SCRIPT(ClassName) \
    public: ClassName(); \
    \
        static ClassName createDummy(){\
            return ClassName();\
        }\
        static ClassName constructNew(){\
            return ClassName();\
        }\
    private: \
        STATIC_SCRIPT_ADDER_FUNCTION(ClassName) \
        friend class ComponentsAssembly;

#define GAME_SCRIPT_DEP() {}


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

    virtual void Start();
    virtual void render() override;//TODO: Test if this override will cause any problem.
    virtual void update() ;

    Component();
    virtual ~Component();
};

} /* namespace Golem */

#endif /* COMPONENT_H_ */
