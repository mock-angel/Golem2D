/*
 * GameWindow.cpp
 *
 *  Created on: 31-May-2020
 *      Author: anantha
 */

#include "GameWindow.h"

#include <iostream>

#include "Shader.h"
#include "Math/Vector2.h"
#include "Node.h"

GameWindow::GameWindow() {
    // TODO Auto-generated constructor stub
    std::cout << "hello" << std::endl;

    Golem::Vector2 vec(0, 1.999);

    Golem::Node* node = new Golem::Node(this);
    getNodeHandler()->addNode(node);
}

GameWindow::~GameWindow() {
    // TODO Auto-generated destructor stub
}

void GameWindow::awake(){
    std::cout << "GameWindow::awake executing"<<std::endl;

    std::string vshader = "src/testVShader";
    std::string fshader = "src/testFShader";

    Golem::Shader(vshader, fshader);
}

void GameWindow::render(){



}
