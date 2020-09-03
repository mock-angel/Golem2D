/*
 * GameWindow.h
 *
 *  Created on: 31-May-2020
 *      Author: anantha
 */

#ifndef GAMEWINDOW_H_
#define GAMEWINDOW_H_

#include "Window.h"

class GameWindow: public Golem::Window {
public:
    GameWindow();
    virtual ~GameWindow();
    void render() override;

    void awake() override;
};

#endif /* GAMEWINDOW_H_ */
