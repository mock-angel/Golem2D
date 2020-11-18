/*
 * Sprite.cpp
 *
 *  Created on: 27-Jun-2020
 *      Author: anantha
 */

#include "Sprite.h"

#include "../../Window.h"
#include "../../Components/Renderable.h"
#include "../../Components/Color.h"
#include "../../Graphics/Textures/Texture.h"

#include "../../Graphics/Shader/Shader.h"
#include "../../Debug.h"
#include "../../Game.h"
#include "../../Res/Scripts/Transform.h"

namespace Golem {

Sprite::Sprite()  : Renderable(){

    std::string vshader = "src/testVShader";
    std::string fshader = "src/testFShader";

    t.load("src/ss.jpg");

    //setShader(Golem::Shader(vshader, fshader));
    setShader(Game::getShaderController().lock()->getShader("DefaultShader"));
    //const glm::vec3& v1 = Color::white.getVector();

    unsigned int VBO, VBO2, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    //glGenBuffers(1, &VBO2);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    float vertices[] = {
        // positions          // colors           // texture coords
         1.f,  1.f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
         1.f, -1.f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
        -1.f, -1.f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        -1.f,  1.f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left
    };

    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //glGenBuffers(1, &VBO2);
    //glBindBuffer(GL_ARRAY_BUFFER, VBO2);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(texture_coords), texture_coords, GL_STATIC_DRAW);
    // texture coord attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);


    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    //t.load("src/ss.png");
    _VAO = VAO;
    glBindVertexArray(0);
    spriteShader.setInt("texture1", 0);
}

void Sprite::render(){
    //Debug::log("Sprite::render() called");

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, t.get());

    spriteShader.use();
    glBindVertexArray(_VAO);

    spriteShader.setVec3("ourColor", Color::white.getVector());

    glm::mat4 projView_matrix = Game::getCamera().getClipMatrix();

    spriteShader.setMat4("clip", projView_matrix);
    //glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
    glUseProgram(0);
}


void Sprite::render(std::weak_ptr<Transform> transform){
    //Debug::log("Sprite::render() called");
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, t.get());

    spriteShader.use();
    glBindVertexArray(_VAO);

    spriteShader.setVec3("ourColor", Color::white.getVector());

    glm::mat4 projView_matrix = Game::getCamera().getClipMatrix();

    spriteShader.setMat4("clip", projView_matrix * transform.lock()->getModelMatrix());
    //glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
    glUseProgram(0);
}

Sprite::~Sprite() {

    // TODO Auto-generated destructor stub
}

} /* namespace Golem */
