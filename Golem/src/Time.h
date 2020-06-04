/*
 * Time.h
 *
 *  Created on: 01-Jun-2020
 *      Author: anantha
 */

#ifndef TIME_H_
#define TIME_H_

#include "Window.h"

namespace Golem {

class Time {
public:
    static double time() { return Time::m_time ; }
    static double deltaTime() { return Time::m_deltaTime ; }
    static double framesPerSecond() { return Time::m_framesPerSecond ; }
    static double timePerFrame() { return Time::m_timePerFrame ; }

private:
    static double m_time;
    static double m_deltaTime;
    static long m_framesPerSecond;
    static double m_timePerFrame;

    friend void Window::GameLoop();

    static void time(double time) { Time::m_time = time; }
    static void deltaTime(double deltaTime) { Time::m_deltaTime  = deltaTime; }
    static void framesPerSecond(long framesPerSecond) { Time::m_framesPerSecond  = framesPerSecond; }
    static void timePerFrame(double timePerFrame) { Time::m_timePerFrame  = timePerFrame; }
};

} /* namespace Golem */

#endif /* TIME_H_ */
