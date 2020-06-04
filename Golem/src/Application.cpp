/*
 * Application.cpp
 *
 *  Created on: 31-May-2020
 *      Author: anantha
 */

#include <GL/glew.h>

#include "Application.h"

namespace Golem {

//template <typename T>
Application::Application() {
    //GLenum err = glewInit();
    // TODO Auto-generated constructor stub

}

//template <typename T>
Application::~Application() {
    if(m_createdWindow != nullptr) delete m_createdWindow;
}

//template <typename T>
void Application::CreateWindow(std::string t_title, Window* t_window , std::pair<int, int> t_size){
    if(t_window  == nullptr) m_createdWindow = new Window();

    else m_createdWindow = t_window ;

    m_createdWindow->Open();
}

} /* namespace Golem */
