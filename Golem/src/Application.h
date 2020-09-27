/*
 * Application.h
 *
 *  Created on: 31-May-2020
 *      Author: anantha
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "Window.h"

#include <memory>

namespace Golem {

//template<typename T>
class Application {
public:
    Application();
    virtual ~Application();

    void CreateWindow(std::string t_title = "", std::shared_ptr<Window> window = std::shared_ptr<Window>(), std::pair<int, int> t_size = {592, 480});

    static std::shared_ptr<Window> m_createdWindow;
    static std::weak_ptr<Window> getWindow(){return m_createdWindow;};

private:

};
//template class Application<Window>;

} /* namespace Golem */

#endif /* APPLICATION_H_ */
