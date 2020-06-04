/*
 * WindowEvents.cpp
 *
 *  Created on: 31-May-2020
 *      Author: anantha
 */

#include <SDL2/SDL.h>
#include "WindowEvents.h"

namespace Golem {

void WindowEvents::processEvents(){

    SDL_Event e;

    while (SDL_PollEvent(&e) != 0){
        if( e.type == SDL_WINDOWEVENT )
            handleWindowEvent(e);

    }
}

} /* namespace Golem */
