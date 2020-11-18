/*
 * Gui.h
 *
 *  Created on: 03-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_GUI_H_
#define CORE_GUI_H_

#include <SDL2/SDL.h>

namespace Golem {

class Gui {
public:
    Gui();
    virtual ~Gui();

    static SDL_Window* sdl_Window;

    static void Init(SDL_Window* t_sdlwindow, SDL_GLContext context);
    static void Cleanup();

    static void NewFrame();
    static void RenderGUI();
};

} /* namespace Golem */

#endif /* CORE_GUI_H_ */
