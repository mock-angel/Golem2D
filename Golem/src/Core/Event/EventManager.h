/*
 * EventManager.h
 *
 *  Created on: 02-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_EVENT_EVENTMANAGER_H_
#define CORE_EVENT_EVENTMANAGER_H_

#include "EventType.h"

#include <memory>
#include <SDL2/SDL.h>



namespace Golem {

class EventManager {
public:
    EventManager();
    virtual ~EventManager();

    void Subscribe();
    void UnSubscribe();

    void publish();
private:



    //void OnSdlEvent(SDL_Event& e);
    //void OnEvent();
    //void SDLEventToGolemEvent(SDL_Event& e);
    //friend class Game;
};

} /* namespace Golem */

#endif /* CORE_EVENT_EVENTMANAGER_H_ */
