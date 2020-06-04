/*
 * GameWindow.cpp
 *
 *  Created on: 31-May-2020
 *      Author: anantha
 */

#include <iostream>

#include "GameWindow.h"
#include "Shader.h"

GameWindow::GameWindow() {
    // TODO Auto-generated constructor stub
    std::cout << "hello";
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
