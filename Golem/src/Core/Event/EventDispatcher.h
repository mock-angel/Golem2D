/*
 * EventDispatcherr.h
 *
 *  Created on: 12-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_EVENT_EVENTDISPATCHER_H_
#define CORE_EVENT_EVENTDISPATCHER_H_

#include <functional>

#include "Event.h"

namespace Golem {

class EventDispatcher {

public:
    EventDispatcher(Event& event): event_ref(&event){};
    virtual ~EventDispatcher();

    template<typename EventType>
    void dispatch(std::function<void(EventType&)> fun){
        if(event_ref->GetEventType() == EventType::GetStaticType())
            fun((EventType)(*event_ref));
    }
private:
    Event* event_ref;
};



} /* namespace Golem */

#endif /* CORE_EVENT_EVENTDISPATCHER_H_ */
