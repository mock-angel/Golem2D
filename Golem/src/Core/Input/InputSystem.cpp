/*
 * InputSystem.cpp
 *
 *  Created on: 02-Nov-2020
 *      Author: anantha
 */

#include "InputSystem.h"
#include "../../Game.h"
#include "Debug.h"

namespace Golem {

InputSystem::InputSystem() {
    // TODO Auto-generated constructor stub
    //Event::typr
}

InputSystem::~InputSystem() {
    // TODO Auto-generated destructor stub
}

void InputSystem::handleRawInput(SDL_Event& e){

    if( e.type == SDL_WINDOWEVENT ){

        if(e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED){
            Debug::log("window size changed");
            WindowResizedEvent windowResizedEvent(e.window.data1, e.window.data2);
            Game::getEventBus().lock()->Publish(windowResizedEvent);

            //Game::OnEvent(windowResizedEvent);
        }
    }


}

} /* namespace Golem */
