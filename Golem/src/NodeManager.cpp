/*
 * NodeManager.cpp
 *
 *  Created on: 31-May-2020
 *      Author: anantha
 */

#include "NodeManager.h"

namespace Golem {

NodeManager::NodeManager() {
    // TODO Auto-generated constructor stub

}

NodeManager::~NodeManager() {
    // TODO Auto-generated destructor stub
}

void NodeManager::DestroyNode(Node* t_node){

    m_nodeLinkedList.remove(t_node);

    delete t_node;

}

void NodeManager::addNode(Node* t_node){
    m_nodes_umap.insert({t_node->GetRID(), t_node});
    m_nodeLinkedList.insert(t_node);
}

void NodeManager::removeNode(Node* t_node){
    m_nodes_umap.erase(t_node->GetRID());
    m_nodeLinkedList.remove(t_node);
}

void NodeManager::expungeNode(Node* t_node){
    removeNode(t_node);
    //Do more stuff here.
    t_node->Destroy();
}

void NodeManager::updateNodes(){

    if(!m_nodeLinkedList.isEmpty()){
        Node* front = m_nodeLinkedList.front();
        Node* searching = front;

        while(searching != nullptr) {
            searching->Update();
            searching = searching->next();
        }

    }

}

void NodeManager::RenderNodes(){

}

} /* namespace Golem */
