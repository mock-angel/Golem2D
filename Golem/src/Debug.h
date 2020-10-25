/*
 * Debug.h
 *
 *  Created on: 25-Sep-2020
 *      Author: anantha
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#include <string>
#include <iostream>

namespace Golem {

class Debug {
public:
    Debug();
    virtual ~Debug();

    static void log(const std::string& str_);
    static void log(const std::string& str_1, const std::string& str_2);
};

} /* namespace Golem */

#endif /* DEBUG_H_ */
