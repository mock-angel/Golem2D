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


#include "Component.h"
#include "Math/Quaternion.h"
#include "Math/Vector3.h"

namespace Golem {

class Transform;
class NodeController;

enum HandleType{
    VECTORS,
    UNORDERED_MAPS
};

class NodeLinkedList;
class Window;

class Node {
public:
    Node();
    virtual ~Node();

    int GetRID(){return m_rid;};

    HandleType childHandleType = VECTORS;

    void Update();
    void Awake();
    static void Destroy(std::weak_ptr<Node> t_nodeToDestroy);

    /* NodeLinkedList Method */

    Node* next(){return m_next_node;};

    /* Node statics */

    // Instantiate a new node.
    //static Node* Instantiate(){return new Node();};

    template <typename T>
        static T* Instantiate(Transform transform);

    template <typename T>
        static T* Instantiate(Vector3 position, Quaternion rotation);


    static std::weak_ptr<Node>  Instantiate(std::weak_ptr<Node> nodeObject, Vector3 position, Quaternion rotation);

    static std::weak_ptr<Node>  Instantiate(Vector3 position = Vector3(), Quaternion rotation = Quaternion());
    /* Components */

    std::list<std::shared_ptr<Component>> m_nodeComponents;

    template <typename T>
        T getComponent();
    void addComponent(std::shared_ptr<Component> component);
    void removeComponent(std::shared_ptr<Component> component);


    void setController(std::weak_ptr<NodeController> t_nodeController){
        m_nodeController = t_nodeController;
    }

    std::weak_ptr<NodeController> getController(){
        return m_nodeController;
    }

    static void print(std::string _str);

private:
    int m_rid = 0;

    Window* m_window;

    std::vector<Node*> m_childNodesVec;
    std::map<int, Node*> m_childNodesUMap;

    Node* m_next_node = nullptr;
    Node* m_prev_node = nullptr;

    void _register();

    template<typename Base, typename T>
    inline bool instanceof() {
       return std::is_base_of<Base, T>::value;
    }

    friend class NodeLinkedList;



    std::weak_ptr<NodeController> m_nodeController;
};

} /* namespace Golem */

#endif /* NODE_H_ */
