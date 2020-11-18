/*
 * InputSystem.h
 *
 *  Created on: 02-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_INPUT_INPUTSYSTEM_H_
#define CORE_INPUT_INPUTSYSTEM_H_

#include <string>

#include <SDL2/SDL.h>

#include "../Event/Event.h"
#include "../Event/EventManager.h"
//#include "../../Game.h"

namespace Golem {

class InputSystem {
public:
    InputSystem();
    virtual ~InputSystem();

    std::string VerticalAxis = "Vertical";
    std::string HorizontalAxis = "Horizontal";

    std::string Jump = "Jump";

    void handleRawInput(SDL_Event& e);

};

} /* namespace Golem */

#endif /* CORE_INPUT_INPUTSYSTEM_H_ */
