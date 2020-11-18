/*
 * WindowEvents.cpp
 *
 *  Created on: 31-May-2020
 *      Author: anantha
 */

#include <SDL2/SDL.h>
#include "WindowEvents.h"

#include "Game.h"
#include "imgui_impl_sdl.h"

namespace Golem {

void WindowEvents::processEvents(){

    SDL_Event e;

    std::shared_ptr<InputSystem> inputSystem = Game::getInputSystem().lock();

    while (SDL_PollEvent(&e) != 0){

        if( e.type == SDL_WINDOWEVENT )
            handleWindowEvent(e);

        ImGui_ImplSDL2_ProcessEvent(&e);
        inputSystem->handleRawInput(e);
    }

}

} /* namespace Golem */
