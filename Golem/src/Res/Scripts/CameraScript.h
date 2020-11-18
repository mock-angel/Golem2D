/*
 * CameraScript.h
 *
 *  Created on: 07-Nov-2020
 *      Author: anantha
 */

#ifndef RES_SCRIPTS_CAMERASCRIPT_H_
#define RES_SCRIPTS_CAMERASCRIPT_H_

#include "Graphics/Camera/Camera.h"

#include "Core/Event/Event.h"
#include "Debug.h"
#include "Component.h"
#include SCRIPT_HEADERS
#include "../../Core/Event/EventCallback.h"

namespace Golem {

class IWindowEventListener{
public:
    virtual void OnWindowResized(){};
    virtual void OnWindowFocusGained(){};
    virtual void OnWindowFocusLost(){};
    virtual void OnWindowRestored(){};

    IWindowEventListener(){};
    virtual ~IWindowEventListener(){};
};

class CameraScript : public Component{
    GAME_SCRIPT(CameraScript)

public:
    Camera m_camera;
    std::shared_ptr<IEventCallback> dispacher;

    void Start();
    void OnWindowResized(Event& event){
        WindowResizedEvent *w_event = (WindowResizedEvent*)((&event)); //static_cast<WindowResizedEvent>(event);
        Debug::log("Resize event called");
    };

    virtual ~CameraScript();
};

} /* namespace Golem */

#endif /* RES_SCRIPTS_CAMERASCRIPT_H_ */
