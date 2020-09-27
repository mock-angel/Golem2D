/*
 * Game.cpp
 *
 *  Created on: 04-Sep-2020
 *      Author: anantha
 */

#include "Game.h"

#include "Debug.h"
#include "Window.h"

namespace Golem {

std::weak_ptr<Window> Game::m_window;
std::weak_ptr<NodeController> Game::m_nodeControllerStatic;
std::weak_ptr<ComponentController> Game::m_componentControllerStatic;

Game::Game() {
    Node::print("Game:: Constructing");

    /* Create Node Controller. */
    m_nodeManager = std::shared_ptr<NodeController>(new NodeController());
    m_nodeControllerStatic = m_nodeManager;

    /* Create Component Controller. */
    m_componentController = std::shared_ptr<ComponentController>(new ComponentController());
    m_componentControllerStatic = m_componentController;


}

Game::~Game() {
    // TODO Auto-generated destructor stub
}

void Game::update() {
    //Debug::log("Game::update() called");

   /* Update nodes. */
   m_nodeManager->updateNodes();

   /* Update components. */
   m_componentController->updateComponents();
}

void Game::render() {
    //Debug::log("Game::render() called");

    /* Render Components. */
    m_componentController->renderComponents();
}

} /* namespace Golem */
