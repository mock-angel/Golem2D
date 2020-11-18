/*
 * Event.h
 *
 *  Created on: 02-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_EVENT_EVENT_H_
#define CORE_EVENT_EVENT_H_

#include <functional>
#include <SDL2/SDL.h>

#include <stdint.h>

#include "EventType.h"

namespace Golem {

enum EventTypeEnum{
    None = 0,
    WindowEventType,

    KeyboardEventType,

    MouseMotionEventType,
    MouseButtonEventType,
    MouseWheelEventType,

    GameEventType,
    CustomEventType
};

#define BIT(num) num << 2

enum EventCategory{
    MouseEventCategory = BIT(1),
    KeyboardEventCategory = BIT(2),
    InputEventCategory = BIT(3),
    CustomEventCategory = BIT(4),
    WindowEventCategory = BIT(5)
};

#define EVENT_CLASS_TYPE(type) static EventTypeEnum GetStaticEventType() {return  type;}\
        virtual EventTypeEnum GetEventType() const {return  type;}

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}


class Event{
    //friend class EventDispacher;
public:
    Event(){};
    virtual ~Event(){};

    static EventTypeEnum GetStaticType(){return EventTypeEnum::None;}
    virtual EventTypeEnum GetEventType() const = 0;
    virtual int GetCategoryFlags() const = 0;
    /*virtual EventTypeEnum GetEventType() const{
        return type;
    }*/

protected:
    EventTypeEnum m_Type = EventTypeEnum::None;
};

class KeyEvent: public Event{
public:
    inline int GetKeyCode() const { return m_KeyCode;}

    EVENT_CLASS_TYPE(EventTypeEnum::KeyboardEventType)
protected:
    KeyEvent(int keyCode) : m_KeyCode(keyCode){}

    int m_KeyCode;
};

class KeyPressedEvent: public KeyEvent{
public:
    KeyPressedEvent(int keyCode, int repeatCount)
        : KeyEvent(keyCode), m_RepeatCount(repeatCount){}

protected:

private:
    int m_RepeatCount;
};



struct WindowEvent: public Event{
    WindowEvent(){m_Type = EventTypeEnum::WindowEventType;}
    SDL_Event sdl_event;

    EVENT_CLASS_TYPE(EventTypeEnum::WindowEventType)

};

class WindowResizedEvent: public WindowEvent{
public:
    WindowResizedEvent(int t_width, int t_height)
        : m_width(t_width), m_height(t_height){m_Type = EventTypeEnum::WindowEventType;}
    EVENT_CLASS_CATEGORY(EventCategory::WindowEventCategory)

    int getWidth(){return m_width;}
    int getHeight(){return m_height;}
private:
    int m_width;
    int m_height;
};

class EventCallbackBase{
public:
    EventCallbackBase();
    virtual ~EventCallbackBase();

    virtual void call() = 0;

};

class MouseMovedEvent : public Event{
public:
    MouseMovedEvent(float x, float y)
        : m_MouseX(x), m_MouseY(y) {}

    inline float GetX() const { return m_MouseX; }
    inline float GetY() const { return m_MouseY; }

    EVENT_CLASS_TYPE(EventTypeEnum::MouseMotionEventType)
    EVENT_CLASS_CATEGORY(EventCategory::MouseEventCategory | EventCategory::InputEventCategory)
private:
    float m_MouseX, m_MouseY;

};

class MouseButtonEvent : public Event{
public:
    MouseButtonEvent(int buttonInt)
        : m_Button(buttonInt) {}

    inline float GetButton() const { return m_Button; }

    EVENT_CLASS_TYPE(EventTypeEnum::MouseButtonEventType)
    EVENT_CLASS_CATEGORY(EventCategory::MouseEventCategory | EventCategory::InputEventCategory)

private:
    int m_Button;
};

} /* namespace Golem */
#endif /* CORE_EVENT_EVENT_H_ */
