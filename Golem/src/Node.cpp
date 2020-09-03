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


namespace Golem {

Node::Node() {
    m_window = Window::Instance;
}

Node::Node(Window* t_window) {
    m_window = t_window;
}

Node::~Node() {
    // TODO Auto-generated destructor stub
}

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

void Node::Destroy(){
    m_window->getNodeHandler()->DestroyNode(this);
    print("Node::destroy() called");
}

template <typename T>
T Node::GetComponent(){
    bool assertVal = !instanceof<Node, T>();
    assert( assertVal );

    std::list<Component*>::iterator it;

    for(it = m_nodeComponents.begin(); it != m_nodeComponents.end(); ++it)
         return *it;
            //std::is_convertible<>;

}

template <typename T>
     T* Node::Instantiate(Transform transform){

        bool assertVal = !instanceof<Node, T>();
        assert( assertVal );

        T* createdNode = new T();

        //if(createdNode.is_base_of<Node>());

        //createdNode->parentTransform = transform;

        return createdNode;
    };

template <typename T>
     T* Node::Instantiate(Vector3 position, Quaternion rotation){

        bool assertVal = !instanceof<Node, T>();
        assert( assertVal );

        T* createdNode = new T();
        //createdNode->parentTransform = transform;

        return createdNode;
    };

void Node::print(std::string _str){

    std::cout << _str << std::endl;
}

} /* namespace Golem */
