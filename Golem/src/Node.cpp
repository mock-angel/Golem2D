/*
 * Node.cpp
 *
 *  Created on: 31-May-2020
 *      Author: anantha
 */

#include <algorithm>

#include "Node.h"
#include "Window.h"

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

void Node::RemoveChild(int t_rid){

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
}

//User Functions
void Node::Awake(){

}

void Node::Update(){

}

void Node::destroy(){
    m_window->getNodeHandler()->DestroyNode(this);
}

} /* namespace Golem */
