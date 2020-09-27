/*
 * Sprite.h
 *
 *  Created on: 27-Jun-2020
 *      Author: anantha
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include "../Component.h"
#include "../Shader.h"

namespace Golem {

class Window;

class Sprite : public Component {

    //Shader fragmentShader;
    //Shader vertexShader;
    Shader spriteShader;

public:
    Sprite(Window* t_window);
    virtual ~Sprite();

    void render() override;

};

} /* namespace Golem */

#endif /* SPRITE_H_ */
