/*
 * GolemList.h
 *
 *  Created on: 03-Sep-2020
 *      Author: anantha
 */

#ifndef CORE_MATH_GOLEMLIST_H_
#define CORE_MATH_GOLEMLIST_H_

#include <list>

namespace Golem {

template <typename T>
class GolemList {

    std::list<T> m_list;

public:
    GolemList();
    virtual ~GolemList();

    void add(){
        std::list<T> li = getList();
    }
    void remove();


    std::list<T>& getList(){

        return m_list;
    }

};

} /* namespace Golem */

#endif /* CORE_MATH_GOLEMLIST_H_ */
