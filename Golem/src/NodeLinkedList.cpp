/*
 * NodeLinkedList.cpp
 *
 *  Created on: 03-Jun-2020
 *      Author: anantha
 */

#include "NodeLinkedList.h"

#include "Debug.h"


namespace Golem {

NodeLinkedList::NodeLinkedList() {
    // TODO Auto-generated constructor stub
}

NodeLinkedList::~NodeLinkedList() {
    // TODO Auto-generated destructor stub
}

void NodeLinkedList::insert(Node* node) {

    if(!isEmpty()){
        Debug::log("isempty");
        m_rear->m_next_node = node;
        node->m_prev_node = m_rear;
        //node->m_next_node = nullptr;
        m_rear = node;
    }
    else m_front = m_rear = node;
}

void NodeLinkedList::remove(Node*node) {

    Node* next_node = node->m_next_node;
    Node* prev_node = node->m_prev_node;

    if(next_node != nullptr)
        next_node->m_prev_node = prev_node;

    if(prev_node != nullptr)
        prev_node->m_next_node = next_node;

    if(node == m_front) m_front = next_node;
    if(node == m_rear) m_rear = prev_node;

    node->m_next_node = node->m_prev_node = nullptr;
}

bool NodeLinkedList::isEmpty(){
    return (m_front == nullptr) and (m_rear == nullptr);
}

Node* NodeLinkedList::front(){
    return m_front;
}

Node* NodeLinkedList::rear(){
    return m_front;
}

} /* namespace Golem */
