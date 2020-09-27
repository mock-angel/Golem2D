/*
 * Node.cpp
 *
 *  Created on: 31-May-2020
 *      Author: anantha
 */

#include "Node.h"

#include <assert.h>

#include <algorithm>
#include <iostream>
#include <type_traits>

#include "Window.h"
#include "Transform.h"
#include "Math/Vector3.h"
#include "Math/Quaternion.h"
#include "Game.h"
#include "NodeController.h"

namespace Golem {

Node::Node() {

}

Node::~Node() {
    // TODO Auto-generated destructor stub
}
/*
void Node::AddChild(Node* t_child){

    if(childHandleType == VECTORS)
        m_childNodesVec.push_back(t_child);

    else if(childHandleType == UNORDERED_MAPS)
        m_childNodesUMap.insert({t_child->GetRID(), t_child});
}

//void Node::AddChild(unsigned int rid){
//    m_childNodes.insert({rid, child});
//}

void Node::RemoveChild(Node* t_child){

    if(childHandleType == VECTORS)
        std::remove(m_childNodesVec.begin(), m_childNodesVec.end(), t_child);

    else if(childHandleType == UNORDERED_MAPS)
        m_childNodesUMap.erase(t_child->GetRID());
}
*/
/*void Node::RemoveChild(int t_rid){

    if(childHandleType == VECTORS){
        //Remove child from vector.
        //std::remove(m_childNodesVec.begin(), m_childNodesVec.end(), 20);

        for(long unsigned int i = 0; i < m_childNodesVec.size(); i++){

            if(m_childNodesVec[i]->GetRID() == t_rid){

                m_childNodesVec.erase(m_childNodesVec.begin() + i);

                break;
            }
        }

    }else if(childHandleType == UNORDERED_MAPS)
        m_childNodesUMap.erase(t_rid);
}*/

//User Functions
void Node::Awake(){
    print("Node::Awake() called");
}

void Node::Update(){
    print("Node::Update() called");
}

void Node::Destroy(std::weak_ptr<Node> t_nodeToDestroy){
    //m_window->getNodeHandler()->DestroyNode(this);
    print("Node::destroy() called (TODO!!)");
}

template <typename T>
    T Node::getComponent(){
        bool assertVal = !instanceof<Node, T>();
        assert( assertVal );

        std::list<std::shared_ptr<Component>>::iterator it;

        for(it = m_nodeComponents.begin(); it != m_nodeComponents.end(); ++it)
             return *it;
                //std::is_convertible<>;

    }
/*
template <typename T>
    T* Node::Instantiate(Transform transform){

        bool assertVal = !instanceof<Node, T>();
        assert( assertVal );

        T* createdNode = new T();

        //if(createdNode.is_base_of<Node>());

        //createdNode->parentTransform = transform;

        return createdNode;
    };
*/

template <typename T>
    T* Node::Instantiate(Vector3 position, Quaternion rotation){

        bool assertVal = !instanceof<Node, T>();
        assert( assertVal );

        T* createdNode = new T();
        //createdNode->parentTransform = transform;

        return createdNode;
    };

std::weak_ptr<Node> Node::Instantiate(std::weak_ptr<Node> nodeObject, Vector3 position, Quaternion rotation){

    std::shared_ptr<Node> createdNode = std::make_shared<Node>();

    //Add to list
    std::weak_ptr<Golem::NodeController> activeNodeController = Game::getNodeController();
    createdNode->setController(activeNodeController);
    activeNodeController.lock()->addNode(createdNode);

    return createdNode;
};

std::weak_ptr<Node> Node::Instantiate(Vector3 position , Quaternion rotation ){
    Node::print("printing node");
    std::shared_ptr<Node> createdNode = std::make_shared<Node>();

    std::weak_ptr<Golem::NodeController> activeNodeController = Game::getNodeController();

    if (auto spt = activeNodeController.lock()) { // Has to be copied into a shared_ptr before usage
        std::cout << " NOT exprited" << "\n";
    }
    else {
        std::cout << "gw is expired\n";
    }

    createdNode->setController(activeNodeController);
    activeNodeController.lock()->addNode(createdNode);
    activeNodeController.lock()->updateNodes();
    return createdNode;
};

void Node::print(std::string _str){

    std::cout << _str << std::endl;
}

void Node::addComponent(std::shared_ptr<Component> component){
    m_nodeComponents.push_back(component);

    Game::getComponentController().lock()->add(component);
}

void Node::removeComponent(std::shared_ptr<Component> component){
    auto it = std::find(m_nodeComponents.begin(), m_nodeComponents.end(), component);

    if (it != m_nodeComponents.end())
        m_nodeComponents.erase(it);

    else print("Couldn't remove component: Component not found.");
}

} /* namespace Golem */
