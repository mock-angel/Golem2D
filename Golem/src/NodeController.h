/*
 * NodeManager.h
 *
 *  Created on: 31-May-2020
 *      Author: anantha
 */

#ifndef NODECONTROLLER_H_
#define NODECONTROLLER_H_

#include <unordered_map>
#include <memory>

#include "Node.h"
#include "NodeLinkedList.h"

namespace Golem {

class NodeController {
public:
    NodeController();
    virtual ~NodeController();

    void addNode(std::shared_ptr<Node> t_node);
    void removeNode(std::shared_ptr<Node> t_node);

    void updateNodes();
    void RenderNodes();

    void RenderComponents();



private:
    std::unordered_map<int, std::shared_ptr<Node>> m_nodes_umap;
    NodeLinkedList m_nodeLinkedList;
};

} /* namespace Golem */

#endif /* NODECONTROLLER_H_ */
