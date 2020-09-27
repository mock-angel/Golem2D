/*
 * Sprite.cpp
 *
 *  Created on: 27-Jun-2020
 *      Author: anantha
 */

#include "Sprite.h"

#include "../Window.h"
#include "../Components/Renderable.h"
#include "../Shader.h"
#include "../Debug.h"

namespace Golem {

Sprite::Sprite()  : Renderable(){

    std::string vshader = "src/testVShader";
    std::string fshader = "src/testFShader";

    setShader(Golem::Shader(vshader, fshader));

    unsigned int VBO, VBO2, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &VBO2);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, VBO2);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(colors), colors, GL_STATIC_DRAW);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0 * sizeof(float), (void*)(0 * sizeof(float)));
    glEnableVertexAttribArray(1);

    _VAO = VAO;
}

void Sprite::render(){
    Debug::log("Sprite::render() called");

    //glClearColor(0.5f, 0.3f, 0.3f, 1.0f);
    //glClear(GL_COLOR_BUFFER_BIT);
    //return;
    spriteShader.use();


    glBindVertexArray(_VAO);
    //glUniform3f(glGetUniformLocation(spriteShader.getID(), "ourColor"), .1, .1, 1);
    spriteShader.setVec3("ourColor", glm::vec3(0,1,0));
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glUseProgram(0);
}

Sprite::~Sprite() {

    // TODO Auto-generated destructor stub
}

} /* namespace Golem */
