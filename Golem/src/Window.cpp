/*
 * Window.cpp
 *
 *  Created on: 31-May-2020
 *      Author: anantha
 */
#include <GL/glew.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <SDL2/SDL_opengl.h>

#include <chrono>
#include <ctime>
#include <iostream>

#include <typeindex>
#include <unordered_map>

#include "Window.h"

#include "Time.h"
#include "Game.h"
#include "Core/Gui.h"

#include "imgui_impl_opengl3.h"
#include "imgui_impl_sdl.h"
#include "imgui.h"

using namespace std;

namespace Golem {

Window* Window::Instance = nullptr;

Window::Window() {
    // TODO Auto-generated constructor stub
    Instance = this;
}
Window* Window::getWindow(){
    return Instance;
}

Window::~Window() {
    // TODO Auto-generated destructor stub
    Node::print("Window::destroyed...");
}

void Window::GameLoop() {

    std::cout << "Window::GameLoop() started" << std::endl;

    auto start_time = std::chrono::system_clock::now();
    auto current_time = start_time;
    auto prev_time = start_time;
    std::chrono::duration<double> deltaTime_seconds = current_time-prev_time; //elapsed_seconds.count()
    std::chrono::duration<double> elapsed_seconds = current_time-start_time; //elapsed_seconds.count()
    std::chrono::duration<double>  fps_update_time = current_time-start_time;
    fps_update_time++;

    long fps_count = 0;

    bool show_demo_window = true;

    m_game->start();

    while(!m_closed){
        //--Time update chunk.
        prev_time = current_time;
        current_time = std::chrono::system_clock::now();
        elapsed_seconds = current_time-start_time;
        deltaTime_seconds = current_time-prev_time;

        Time::deltaTime(deltaTime_seconds.count());
        Time::time(elapsed_seconds.count());

        fps_count += 1;

        if(fps_update_time < elapsed_seconds){
            fps_update_time++;
            Time::framesPerSecond(fps_count);
            Time::timePerFrame(1.0/fps_count);
            std::cout<<Time::framesPerSecond()<<"fps total "<<Time::time()<<" seconds"<<endl;
            fps_count = 0;
        }
        //---End of Time update chunk.

        {//----Events----//
            processEvents();
        }

        Gui::NewFrame();

        {//----Update----//
            update();
        }

        {//----Render----//
            if (show_demo_window)
                ImGui::ShowDemoWindow(&show_demo_window);

            //Gui::RenderGUI();
            ImGui::Render();

            if(m_shown and !m_minimized){
                render_sequence();
                ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            }
        }

        SDL_GL_SwapWindow(m_sdlWindow);
    }

    std::cout << "Window::GameLoop() stopped at " <<Time::time()<<"s"<< std::endl;

    Cleanup();
}

void Window::Init(){


    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout<<SDL_GetError();
        return;
    }

    m_sdlWindow = SDL_CreateWindow( "Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_width, m_height, m_flags);

    if (m_sdlWindow == nullptr){
        std::cout<<SDL_GetError();
        return;
    }

    m_windowId = SDL_GetWindowID(m_sdlWindow);

    SDL_SetWindowMinimumSize(m_sdlWindow, 320, 320);

    hide();
    //SDL_HideWindow(m_window);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    m_context = SDL_GL_CreateContext(m_sdlWindow);
    SDL_GL_SetSwapInterval(0);

    //self.glSetViewport()

    //self.title = self.m_title

    glewInit();

    Gui::Init(m_sdlWindow, m_sdlWindow);

    m_game = std::make_shared<Game>();

    show();

    awake();

    GameLoop();

    Cleanup();
}

void Window::Open() {
    Init();
    //GameLoop();
}

void Window::InitImGUI() {

    //GameLoop();
}

void Window::Cleanup() {
    Gui::Cleanup();
}

void Window::update() {	//Empty.
    // remains empty
    getGame()->update();
}

void Window::render() {	//Empty.
    // render calls go here.
    //std::cout << "Window::render() done" << std::endl;
    getGame()->render();
}

void Window::handleWindowEvent( SDL_Event& e )
{
    //TODO: remove unnecessary window ID check.

    //If an event was detected for this window
    if( e.type == SDL_WINDOWEVENT && e.window.windowID == m_windowId)// && e.window.windowID == m_windowId)
    //TODO: Avoid unnecessarity searching and calling for events from window.
    {
        //Caption update flag.
        //bool updateCaption = false;

        switch( e.window.event )
        {
        //Window appeared.
        case SDL_WINDOWEVENT_SHOWN:
            m_shown = true;
            printf("W: Show\n");
            break;

        //Window disappeared.
        case SDL_WINDOWEVENT_HIDDEN:
            m_shown = false;
            printf("W: Hide\n");
            break;

        //Get new dimensions and repaint.
        case SDL_WINDOWEVENT_SIZE_CHANGED:

            m_width = e.window.data1;
            m_height = e.window.data2;

            //SDL_RenderPresent( m_renderer );
            //TODO: Rewrite above line for surface render...
            glViewport(0, 0, m_width, m_height);

            break;
        //Repaint on expose.
        case SDL_WINDOWEVENT_EXPOSED:
            //SDL_RenderPresent(m_renderer);

            printf("W: Exposed\n");
            break;

        //Mouse enter.
        case SDL_WINDOWEVENT_ENTER:
            m_mouseFocus = true;

            printf("M: Enter\n");
            break;

        //Mouse exit.
        case SDL_WINDOWEVENT_LEAVE:
            m_mouseFocus = false;

            printf("M: Leave\n");
            break;

        //Keyboard focus gained.
        case SDL_WINDOWEVENT_FOCUS_GAINED:
            m_keyboardFocus = true;

            printf("K: focus Gained\n");
            break;

        //Keyboard focus lost.
        case SDL_WINDOWEVENT_FOCUS_LOST:
            m_keyboardFocus = false;

            printf("W: focus Lost\n");
            break;

        //Window minimized.
        case SDL_WINDOWEVENT_MINIMIZED:
            m_minimized = true;

            printf("W: MINIMIZED\n");
            break;

        //Window maxized.
        case SDL_WINDOWEVENT_MAXIMIZED:
            m_minimized = false;
            printf("W: MAXIMIZED\n");
            break;

        //Window restored.
        case SDL_WINDOWEVENT_RESTORED:
            m_minimized = false;

            printf("W: RESTORED\n");
            break;

        //Hide on close.
        case SDL_WINDOWEVENT_CLOSE:
            SDL_HideWindow( m_sdlWindow );

            SDL_DestroyRenderer(m_renderer);
            SDL_DestroyWindow(m_sdlWindow);

            m_sdlWindow = NULL;
            m_renderer = NULL;
            m_closed = true;
            break;
        }
    }
}

void Window::awake(){
    Node::print("Calling Window::Awake()");
}

void Window::focus(){
    //m_mouseFocus = m_keyboardFocus = true;
    SDL_RaiseWindow( m_sdlWindow );
}

void Window::show(){
    //m_shown = true;
    SDL_ShowWindow( m_sdlWindow );
}

void Window::hide(){
    //m_shown = false;
    SDL_ShowWindow( m_sdlWindow );
}

void Window::maximise(){
    //m_minimized = false;
    SDL_MaximizeWindow( m_sdlWindow );
}

void Window::minimise(){
    //m_minimized = true;
    SDL_MinimizeWindow( m_sdlWindow );
}

void Window::restore(){
    //m_minimized = false;
    SDL_RestoreWindow( m_sdlWindow );
}

int Window::getWidth(){
    return m_width;
}
int Window::getHeight(){
    return m_height;
}

std::shared_ptr<Game> Window::getGame(){
    return m_game;
}

} /* namespace Golem */

