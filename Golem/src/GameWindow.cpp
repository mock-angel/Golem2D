/*
 * GameWindow.cpp
 *
 *  Created on: 31-May-2020
 *      Author: anantha
 */

#include "GameWindow.h"

#include <iostream>
#include <memory>

#include "Node.h"
#include "Component.h"
#include "Core/Math/Vector2.h"
#include "Graphics/Shader/Shader.h"
#include "Res/Scripts/SpriteScript.h"
#include "Res/Scripts/Transform.h"
#include "Res/Scripts/CameraScript.h"
#include "imgui.h"

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

    std::shared_ptr<Golem::Component> c = std::dynamic_pointer_cast<Golem::Component>(std::make_shared<Golem::CameraScript>());
    n.lock()->addComponent(c);
}

void GameWindow::render(){
/*
    ImGui::Begin("Hello, world!");
    if (ImGui::Button("Button"))
    {
    //... my_code
    }
    ImGui::End();*/
}
