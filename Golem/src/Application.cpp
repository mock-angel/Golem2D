/*
 * Application.cpp
 *
 *  Created on: 31-May-2020
 *      Author: anantha
 */

#include "Application.h"

#include <GL/glew.h>
#include <memory>

#include "Game.h"

namespace Golem {

std::shared_ptr<Window> Application::m_createdWindow;

//template <typename T>
Application::Application() {
    //GLenum err = glewInit();
    // TODO Auto-generated constructor stub

}

//template <typename T>
Application::~Application() {
    //if(m_createdWindow != nullptr) delete m_createdWindow;
}

//template <typename T>
void Application::CreateWindow(std::string t_title, std::shared_ptr<Window> t_window, std::pair<int, int> t_size){
    if(t_window  == nullptr) m_createdWindow = std::make_shared<Window>();

    else m_createdWindow = t_window ;

    Game::m_window = m_createdWindow;

    t_window->Open();
}

} /* namespace Golem */
