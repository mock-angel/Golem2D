/*
 * Node.cpp
 *
 *  Created on: 31-May-2020
 *      Author: anantha
 */

#include <assert.h>

#include <algorithm>
#include <iostream>
#include <memory>
#include <type_traits>

namespace Golem {

template <typename T>
    std::weak_ptr<T> Node::getComponent(){

        //bool assertVal = instanceof<Component, T>();
        //assert( assertVal );
    //std::shared_ptr<Golem::Component> component = std::dynamic_pointer_cast<Golem::Component>(std::make_shared<Golem::Transform>());
    //m_nodeComponents.push_back(component);

    //print("NOt WORKING");
        //m_nodeComponents.clear();
        //std::list<std::shared_ptr<Component>>::iterator it;

        //print("NOt WORKING0");
    /*
        print("NOt WORKING0"+ std::to_string(m_nodeComponents.size()));
        for(auto it = m_nodeComponents.begin(); it != m_nodeComponents.end(); ++it){
            print("Iter ...");
            if(instanceof<T>((*it).lock().get())) {
                print("Found!!");
                std::shared_ptr<T> t = std::dynamic_pointer_cast<T>((*it).lock());
                return t;
            }
                //std::is_convertible<>;

        }
        print("NOt FOUND");
        return std::weak_ptr<T>();
        */
    }

} /* namespace Golem */
