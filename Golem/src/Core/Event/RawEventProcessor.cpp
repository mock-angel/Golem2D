/*
 * EventRunner.cpp
 *
 *  Created on: 02-Nov-2020
 *      Author: anantha
 */

#include "RawEventProcessor.h"

#include <SDL2/SDL.h>

#include "Event.h"
#include "EventManager.h"

namespace Golem {

RawEventProcessor::RawEventProcessor() {
    // TODO Auto-generated constructor stub

}

RawEventProcessor::~RawEventProcessor() {
    // TODO Auto-generated destructor stub
}

void RawEventProcessor::process(){
    SDL_Event e;

    while (SDL_PollEvent(&e) != 0){
        if( e.type == SDL_WINDOWEVENT ){
            //eventInfo.type = EventTypeEnum::WindowEvent;
        }
        //handleWindowEvent(e);
    }

    //if(EventManager::Instance != nullptr);
        //EventManager::Instance::handle(eventInfo);
}

} /* namespace Golem */
