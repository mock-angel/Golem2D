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
#include <list>
#include <iterator>
#include <memory>

namespace Golem {

class Transform;
class Component;
class Vector3;
class Quaternion;

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



    void Update();
    void Awake();

    void Destroy();

    /* NodeLinkedList Method */

    Node* next(){return m_next_node;};

    /* Node statics */

    // Instantiate a new node, but user
    // must attach and set all components
    // by code itself, or use copy components
    // (TODO). Prefer to use as dummy node.
    //template <typename T>
    static Node* Instantiate(){return new Node();};

    template <typename T>
        static T* Instantiate(Transform transform);

    template <typename T>
        static T* Instantiate(Vector3 position, Quaternion rotation);

    /* Components */

    std::list<Component*> m_nodeComponents;

    template <typename T>
        T GetComponent();
    void AddComponent(std::shared_ptr<Component>* component);
    void RemoveComponent(std::shared_ptr<Component>* component);
private:
    int m_rid = 0;

    Window* m_window;

    std::vector<Node*> m_childNodesVec;
    std::map<int, Node*> m_childNodesUMap;

    Node* m_next_node = nullptr;
    Node* m_prev_node = nullptr;

    void _register();

    // Child Nodes.
    void AddChild(Node* t_child);
    void RemoveChild(Node* t_child);
    //void RemoveChild(int t_rid);

    //

    template<typename Base, typename T>
    inline bool instanceof() {
       return std::is_base_of<Base, T>::value;
    }

    friend class NodeLinkedList;

    void print(std::string _str);
};

} /* namespace Golem */

#endif /* NODE_H_ */
