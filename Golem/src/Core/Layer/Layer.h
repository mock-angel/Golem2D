/*
 * Layer.h
 *
 *  Created on: 12-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_LAYER_LAYER_H_
#define CORE_LAYER_LAYER_H_

namespace Golem {

class Event;

class Layer {
public:
    Layer();
    Layer(bool t_updates, bool t_renders, bool t_eventListener)
        : m_isEventListener(t_eventListener), m_isUpdatable(t_updates), m_isRenderable(t_renders)  {}
    virtual ~Layer();

    virtual void render();  // Empty base function.
    virtual void update();  // Empty base function.

    virtual void onEvent(Event& t_event);   // Empty base function.
    virtual void onAttach(){}   // Empty base function.
    virtual void onDetach(){}   // Empty base function.

    inline void makeEventListener(bool value){ m_isEventListener =  value;}
    inline void makeUpdatable(bool value) { m_isUpdatable =  value;}
    inline void makeRenderable(bool value) { m_isRenderable =  value;}

    inline bool isEventListener(){return m_isEventListener;}
    inline bool isUpdatable(){return m_isUpdatable;}
    inline bool isRenderable(){return m_isRenderable;}

    //inline bool isModified(){return m_isModified;}
private:
    bool m_isEventListener = true;
    bool m_isUpdatable = true;
    bool m_isRenderable = true;

    //bool m_isModified = false;
};

} /* namespace Golem */

#endif /* CORE_LAYER_LAYER_H_ */
