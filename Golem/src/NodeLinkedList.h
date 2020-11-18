/*
 * NodeLinkedList.h
 *
 *  Created on: 03-Jun-2020
 *      Author: anantha
 */

#ifndef NODELINKEDLIST_H_
#define NODELINKEDLIST_H_

#include <memory>

#include "Node.h"

namespace Golem {

class NodeLinkedList {
public:
    NodeLinkedList();
    virtual ~NodeLinkedList();

    void insert(Node* node);
    void remove(Node* node);

    bool isEmpty();

    Node* front();
    Node* rear();

private:
    Node* m_front = nullptr;
    Node* m_rear = nullptr;

};

} /* namespace Golem */

#endif /* NODELINKEDLIST_H_ */
