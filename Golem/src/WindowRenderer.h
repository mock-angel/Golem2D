/*
 * WindowRenderer.h
 *
 *  Created on: 31-May-2020
 *      Author: anantha
 */

#ifndef WINDOWRENDERER_H_
#define WINDOWRENDERER_H_

#include <iostream>

#include <memory>

#include "NodeController.h"

namespace Golem {

class Game;

class WindowRenderer {
public:

    virtual ~WindowRenderer();
    void render_sequence();//cout<<"WindowRenderer::_render() done" << endl;render();}

    virtual void render() = 0;

    void setGLViewport();

protected:
    int m_width = 480;
    int m_height = 480;

    virtual std::shared_ptr<Game> getGame() = 0;//getNodeHandler() = 0;
};

} /* namespace Golem */

#endif /* WINDOWRENDERER_H_ */
