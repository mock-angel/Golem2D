/*
 * Node.h
 *
 *  Created on: 31-May-2020
 *      Author: anantha
 */

#ifndef NODE_H_
#define NODE_H_

#include <vector>
#include <map>

//#include "Window.h"

namespace Golem {

enum HandleType{
    VECTORS,
    UNORDERED_MAPS
};

class NodeLinkedList;
class Window;

class Node {
public:
    Node();
    Node(Window* t_window);
    virtual ~Node();

    int GetRID(){return m_rid;};

    HandleType childHandleType = VECTORS;

    //UserFunctions.
    void Update();
    void Awake();

    void destroy();

    Node* next(){return m_next_node;};
    static Node* Instantiate(){return new Node();};
private:
    int m_rid = 0;

    Window* m_window;

    std::vector<Node*> m_childNodesVec;
    std::map<int, Node*> m_childNodesUMap;

    void _register();

    void AddChild(Node* t_child);

    void RemoveChild(Node* t_child);
    void RemoveChild(int t_rid);

    friend class NodeLinkedList;

    Node* m_next_node = nullptr;
    Node* m_prev_node = nullptr;

};

} /* namespace Golem */

#endif /* NODE_H_ */
