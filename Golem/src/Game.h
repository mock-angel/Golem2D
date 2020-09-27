/*
 * Game.h
 *
 *  Created on: 04-Sep-2020
 *      Author: anantha
 */

#ifndef GAME_H_
#define GAME_H_

#include <memory>

#include "Window.h"
#include "NodeController.h"
#include "Components/ComponentController.h"

namespace Golem {

class Game {
    std::shared_ptr<NodeController> m_nodeManager;
    std::shared_ptr<ComponentController> m_componentController;

public:
    Game();
    virtual ~Game();

    virtual void update();
    virtual void render();

    static std::weak_ptr<Window> m_window;
    static std::weak_ptr<Window> getWindow(){return m_window;};

    static std::weak_ptr<NodeController> m_nodeControllerStatic;
    static std::weak_ptr<NodeController> getNodeController(){return m_nodeControllerStatic;};

    static std::weak_ptr<ComponentController> m_componentControllerStatic;
    static std::weak_ptr<ComponentController> getComponentController(){return m_componentControllerStatic;};
};

} /* namespace Golem */

#endif /* GAME_H_ */
