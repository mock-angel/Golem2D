/*
 * NodeManager.cpp
 *
 *  Created on: 31-May-2020
 *      Author: anantha
 */

#include "NodeController.h"

namespace Golem {

NodeController::NodeController() {
    // TODO Auto-generated constructor stub
    Node::print("NodeController:: constructed");
}

NodeController::~NodeController() {
    // TODO Auto-generated destructor stub
    Node::print("NodeController:: destructed");
}



void NodeController::addNode(std::shared_ptr<Node> t_node){
    m_nodes_umap.insert({t_node->GetRID(), t_node});
    m_nodeLinkedList.insert(t_node.get());

    Node::print("add Node done");
}

void NodeController::removeNode(std::shared_ptr<Node> t_node){
    m_nodes_umap.erase(t_node->GetRID());
    m_nodeLinkedList.remove(t_node.get());
}

void NodeController::updateNodes(){

    int nodeCount = 0;

    if(!m_nodeLinkedList.isEmpty()){
        Node* front = m_nodeLinkedList.front();
        Node* searching = front;

        while(searching != nullptr) {
            searching->Update();
            searching = searching->next();

            nodeCount++;
        }

    }

    Node::print(std::string("NodeController::update(): nodecount ") + std::to_string(nodeCount) );
}

void NodeController::RenderNodes(){

}

} /* namespace Golem */
