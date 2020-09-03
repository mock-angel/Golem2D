/*
 * NodeManager.h
 *
 *  Created on: 31-May-2020
 *      Author: anantha
 */

#ifndef NODEMANAGER_H_
#define NODEMANAGER_H_

#include <unordered_map>

#include "Node.h"
#include "NodeLinkedList.h"

namespace Golem {

class NodeManager {
public:
    NodeManager();
    virtual ~NodeManager();

    void addNode(Node* t_node);
    void removeNode(Node* t_node);
    void expungeNode(Node* t_node);//Remove and delete.

    void updateNodes();
    void RenderNodes();

    void RenderComponents();

    void DestroyNode(Node* t_node);

private:
    std::unordered_map<int, Node*> m_nodes_umap;

    NodeLinkedList m_nodeLinkedList;
};

} /* namespace Golem */

#endif /* NODEMANAGER_H_ */
