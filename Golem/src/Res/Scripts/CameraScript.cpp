/*
 * CameraScript.cpp
 *
 *  Created on: 07-Nov-2020
 *      Author: anantha
 */

#include "CameraScript.h"

#include "Game.h"
#include "Core/Event/EventBus.h"

namespace Golem {

CameraScript::CameraScript() {
    // TODO Auto-generated constructor stub

}

CameraScript::~CameraScript() {
    // TODO Auto-generated destructor stub
}

void CameraScript::Start(){
    //EventDispacher
    using namespace std::placeholders;
    Debug::log("CameraScript::Start function()");
    std::shared_ptr<EventBus> bus = Game::getEventBus().lock();

    std::bind(&CameraScript::OnWindowResized, this, _1);

    dispacher = std::make_shared<EventCallback<WindowResizedEvent>>(std::bind(&CameraScript::OnWindowResized, this, _1));
    //OnWindowResized();
    bus->Subscribe(EventTypeEnum::WindowEventType, dispacher);
}

} /* namespace Golem */
