/*
 * Input.h
 *
 *  Created on: 02-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_INPUT_INPUT_H_
#define CORE_INPUT_INPUT_H_

#include "../Math/Vector2.h"

#include <string>

namespace Golem {

class Input{

public:
    static Vector2 mousePosition;

    static int GetAxis(const std::string& axisName);//Vertical/Horizontal
    static bool GetButtonDown(const std::string& buttonName);//first frame pressed
    static bool GetButton(const std::string& buttonName);//held down.

    Input();
    virtual ~Input();
};

} /* namespace Golem */

#endif /* CORE_INPUT_INPUT_H_ */
