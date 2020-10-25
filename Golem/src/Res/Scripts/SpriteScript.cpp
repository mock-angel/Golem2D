/*
 * SpriteScript.cpp
 *
 *  Created on: 27-Sep-2020
 *      Author: anantha
 */

#include "SpriteScript.h"

#include "../../Node.h"
#include "Transform.h"

namespace Golem {

SpriteScript::SpriteScript() {
    // TODO Auto-generated constructor stub
    enableRenders(true);

    //transform = std::make_shared<Transform>();
}

SpriteScript::~SpriteScript() {
    // TODO Auto-generated destructor stub
}

void SpriteScript::render(){
    auto transform = getGameObject().lock()->getTransform();
    sprite.render(transform);
}
/*
std::weak_ptr<Transform> SpriteScript::getTransform(){;
        return std::weak_ptr<Transform>(transform);
    }*/

} /* namespace Golem */
