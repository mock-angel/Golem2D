/*
 * WindowRenderer.h
 *
 *  Created on: 31-May-2020
 *      Author: anantha
 */

#ifndef WINDOWRENDERER_H_
#define WINDOWRENDERER_H_

#include <iostream>

namespace Golem {

class WindowRenderer {
public:

    virtual ~WindowRenderer();
    void render_sequence();//cout<<"WindowRenderer::_render() done" << endl;render();}

    virtual void render() = 0;

    void setGLViewport();

protected:
    int m_width = 480;
    int m_height = 480;

};

} /* namespace Golem */

#endif /* WINDOWRENDERER_H_ */
