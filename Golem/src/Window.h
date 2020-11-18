/*
 * Window.h
 *
 *  Created on: 31-May-2020
 *      Author: anantha
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <SDL2/SDL.h>

#include "NodeController.h"
#include "WindowEvents.h"
#include "WindowRenderer.h"

namespace Golem {

class Game;

class Window: public WindowEvents, public WindowRenderer {
public:
    Window();
    virtual ~Window();

    static Window* Instance;
    static Window* getWindow();
    //bool open();

    //Handles window events.
    //void handleEvent( SDL_Event& e );

    //Focuses on window.
    void focus();

    //Shows windows contents.
    void render();

    //Updates windows contents.
    void update();

    //Window dimensions.
    int getWidth();
    int getHeight();

    //Window focii.             --Focus calls.
    bool hasMouseFocus();
    bool hasKeyboardFocus();
    bool isMinimized();

    bool isShown();
    bool isClosed();

    void hide();
    void show();
    void maximise();
    void minimise();
    void restore();

    void close();

    virtual void awake();

    void Open();

    //NodeController* getNodeHandler();//TODO: FIXME: Naming convention is odd.

protected:
    SDL_Renderer* m_renderer = nullptr;

private:
    //Window data.
    SDL_Window* m_sdlWindow = nullptr;

    SDL_GLContext m_context = nullptr; //Graphics Processor.

    unsigned int m_windowId;

    void Init();
    void InitImGUI();
    void GameLoop();
    void Cleanup();

    //Handles window events.
    void handleWindowEvent( SDL_Event& e ) override;

    std::shared_ptr<Game> getGame();

    friend class Time;
    friend class Game;
    //friend class Application;
    //Window dimensions.
    //int m_width = 480;
    //int m_height = 480;

    //Window focus.
    bool m_mouseFocus  = true;              //!< Stores mouse focus state: true if mouse is focused on the window.
    bool m_keyboardFocus = true;            //!< Stores keyboard focus state: true if keyboard is focused on the window.
    bool m_fullScreen  = false;             //!< : true if window is full-screen.
    bool m_minimized  = false;              //!< : true if window is minimized, false if window is restored/visible.

    //Displayed.
    bool m_shown = true;                           //!<
    bool m_closed = false;                          //!< Says if window is still active.

    //NodeController m_nodeManager;

    std::shared_ptr<Game> m_game;

    // Window flags.
    Uint32 m_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL;
};

} /* namespace Golem */

#endif /* WINDOW_H_ */
