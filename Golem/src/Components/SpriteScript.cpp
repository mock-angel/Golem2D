/*
 * SpriteScript.cpp
 *
 *  Created on: 27-Sep-2020
 *      Author: anantha
 */

#include "SpriteScript.h"

namespace Golem {

SpriteScript::SpriteScript() {
    // TODO Auto-generated constructor stub
    enableRenders(true);
}

SpriteScript::~SpriteScript() {
    // TODO Auto-generated destructor stub
}

void SpriteScript::render(){
    sprite.render();
}

} /* namespace Golem */
