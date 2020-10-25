/*
 * GameWindow.cpp
 *
 *  Created on: 31-May-2020
 *      Author: anantha
 */

#include "GameWindow.h"

#include <iostream>
#include <memory>

#include "Shader.h"
#include "Math/Vector2.h"
#include "Node.h"
#include "Component.h"
#include "Res/Scripts/SpriteScript.h"
#include "Res/Scripts/Transform.h"


GameWindow::GameWindow() {
    // TODO Auto-generated constructor stub
    std::cout << "hello" << std::endl;

    Golem::Vector2 vec(0, 1.999);

    //Golem::Node* node = new Golem::Node(this);
    //getNodeHandler()->addNode(node);
}

GameWindow::~GameWindow() {
    // TODO Auto-generated destructor stub
}

void GameWindow::awake(){
    std::cout << "GameWindow::awake executing"<<std::endl;

    //std::string vshader = "src/testVShader";
    //std::string fshader = "src/testFShader";

    //Golem::Shader shader = Golem::Shader(vshader, fshader);



    auto compo = (std::make_shared<Golem::SpriteScript>());
    //auto compo1 = std::make_shared<Golem::SpriteScript>();
    //compo->setShader(shader);
    Golem::Node::print("starting call to Node::Instantiate()");
    auto n = Golem::Node::Instantiate();
    n.lock()->addComponent(compo);
    //Golem::Node::Instantiate().lock()->addComponent(compo1);
    Golem::Node::print("ending call to Node::Instantiate()");

    std::shared_ptr<Golem::Component> component = std::dynamic_pointer_cast<Golem::Component>(std::make_shared<Golem::Transform>());
    n.lock()->addComponent(component);

}

void GameWindow::render(){



}
