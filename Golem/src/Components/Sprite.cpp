/*
 * Sprite.cpp
 *
 *  Created on: 27-Jun-2020
 *      Author: anantha
 */

#include "Sprite.h"

#include "../Window.h"
#include "../Component.h"
#include "../Shader.h"

namespace Golem {

Sprite::Sprite(Window* t_window)  : Component(){
    // TODO Auto-generated constructor stub
}

void Sprite::render(){

    spriteShader.use();
}

Sprite::~Sprite() {

    // TODO Auto-generated destructor stub
}

} /* namespace Golem */
