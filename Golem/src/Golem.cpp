//============================================================================
// Name        : Golem.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<SDL2/SDL.h>

#include <iostream>

#include "Application.h"
#include "GameWindow.h"

using namespace std;

namespace Golem{

}

int main() {
	cout << "main() started" << endl; // prints !!!Hello World!!!

	Golem::Application new_app;
	GameWindow* GameInstance = new GameWindow;

	new_app.CreateWindow("hello", GameInstance);

	return 0;
}
