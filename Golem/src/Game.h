/*
 * Game.h
 *
 *  Created on: 04-Sep-2020
 *      Author: anantha
 */

#ifndef GAME_H_
#define GAME_H_

#include <memory>

#include "Graphics/Camera/Camera.h"
#include "Window.h"
#include "NodeController.h"
#include "Components/ComponentController.h"
#include "Graphics/Shader/ShaderLoader.h"
#include "Core/Event/EventBus.h"
#include "Core/Input/InputSystem.h"
#include "Core/Layer/LayerManager.h"
//#include "Core/ScriptingEngine/ScriptingEngine.h"

namespace Golem {

class Game {
    std::shared_ptr<NodeController> m_nodeManager;
    std::shared_ptr<ComponentController> m_componentController;
    std::shared_ptr<ShaderLoader> m_shaderLoader;
    std::shared_ptr<EventBus> m_eventBus;
    std::shared_ptr<InputSystem> m_inputSystem;
    std::shared_ptr<LayerManager> m_layerManager;
    //std::shared_ptr<ScriptingEngine> m_scriptingEngine;
    Camera camera;

public:
    Game();
    virtual ~Game();

    virtual void update();
    virtual void render();

    void onEvent(Event& t_event);

    void start();
    Camera getConatinedCamera(){
        return camera;
    }

    static std::weak_ptr<Window> m_window;
    static std::weak_ptr<Window> getWindow(){return m_window;}
    static std::weak_ptr<Game> getGame(){return m_window.lock()->getGame();}
    static Camera getCamera(){return m_window.lock()->getGame()->getConatinedCamera();}

    static std::weak_ptr<NodeController> m_nodeControllerStatic;
    static std::weak_ptr<NodeController> getNodeController(){return m_nodeControllerStatic;}

    static std::weak_ptr<ComponentController> m_componentControllerStatic;
    static std::weak_ptr<ComponentController> getComponentController(){return m_componentControllerStatic;}

    static std::weak_ptr<ShaderLoader> m_shaderControllerStatic;
    static std::weak_ptr<ShaderLoader> getShaderController(){return m_shaderControllerStatic;}

    static std::weak_ptr<EventBus> m_eventBusStatic;
    static std::weak_ptr<EventBus> getEventBus(){return m_eventBusStatic;}

    static std::weak_ptr<InputSystem> m_inputSystemStatic;
    static std::weak_ptr<InputSystem> getInputSystem(){return m_inputSystemStatic;}

    void processEvents();
};

} /* namespace Golem */

#endif /* GAME_H_ */
