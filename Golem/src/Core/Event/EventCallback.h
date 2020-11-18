/*
 * EventDispacher.h
 *
 *  Created on: 06-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_EVENT_EVENTCALLBACK_H_
#define CORE_EVENT_EVENTCALLBACK_H_

#include <functional>

#include "Event.h"

namespace Golem {

class IEventCallback{
public:
    virtual void call(Event& t_event) = 0;

protected:
    IEventCallback(){};
    virtual ~IEventCallback(){};
};



template<class T>
class EventCallback: public IEventCallback{
private:
    std::function<void(Event&)> m_fun;

public:
    EventCallback(std::function<void(Event&)> t_fun) : IEventCallback(){
        m_fun = t_fun;
    }

    inline void call(Event& t_event){

        m_fun(t_event);
    }

    //void dispach

    virtual ~EventCallback(){};
};


} /* namespace Golem */

#endif /* CORE_EVENT_EVENTCALLBACK_H_ */
