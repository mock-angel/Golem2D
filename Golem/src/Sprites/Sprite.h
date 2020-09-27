/*
 * Sprite.h
 *
 *  Created on: 27-Jun-2020
 *      Author: anantha
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include "../Components/Renderable.h"
#include "../Shader.h"

namespace Golem {

class Window;

class Sprite : public Renderable {

    //Shader fragmentShader;
    //Shader vertexShader;
    Shader spriteShader;

    int _VAO;
    float vertices_[18] = {
        // positions         // colors
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top
    };

    float vertices[9] = {
        // positions
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
         0.0f,  0.5f, 0.0f   // top
    };

    float colors[9] = {
        // colors
        1.0f, 0.0f, 0.0f,  // bottom right
        0.0f, 1.0f, 0.0f,  // bottom left
        0.0f, 0.0f, 1.0f   // top
    };
public:
    Sprite();
    virtual ~Sprite();

    void render() override;


    void setShader(Shader shader){spriteShader = shader;}
};

} /* namespace Golem */

#endif /* SPRITE_H_ */
