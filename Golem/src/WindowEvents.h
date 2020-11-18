/*
 * WindowEvents.h
 *
 *  Created on: 31-May-2020
 *      Author: anantha
 */

#ifndef WINDOWEVENTS_H_
#define WINDOWEVENTS_H_

#include <SDL2/SDL.h>

namespace Golem {

class WindowEvents {

public:


protected:
    void processEvents();

private:
    //SDL_Event m_event;

    virtual void handleWindowEvent( SDL_Event& e ) = 0;
};

} /* namespace Golem */

#endif /* WINDOWEVENTS_H_ */
