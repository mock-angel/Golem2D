/*
 * Sprite.h
 *
 *  Created on: 27-Jun-2020
 *      Author: anantha
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include "../../Components/Renderable.h"
#include "../Shader/Shader.h"
#include "../Textures/Texture.h"

namespace Golem {

class Window;
class Transform;

class Sprite : public Renderable {
    Texture t;
    //Shader fragmentShader;
    //Shader vertexShader;
    Shader spriteShader;

    int _VAO;
    /*float vertices[12] = {
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left
    };*/

    unsigned int indices[6] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
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
    void render(std::weak_ptr<Transform> transform);

    void setShader(Shader shader){spriteShader = shader;}
};

} /* namespace Golem */

#endif /* SPRITE_H_ */
