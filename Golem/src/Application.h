/*
 * Application.h
 *
 *  Created on: 31-May-2020
 *      Author: anantha
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "Window.h"

namespace Golem {

//template<typename T>
class Application {
public:
    Application();
    virtual ~Application();

    void CreateWindow(std::string t_title = "", Window* t_window = nullptr, std::pair<int, int> t_size = {592, 480});
private:
    Window* m_createdWindow = nullptr;

};
//template class Application<Window>;

} /* namespace Golem */

#endif /* APPLICATION_H_ */
