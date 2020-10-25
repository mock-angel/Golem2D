/*
 * Debug.cpp
 *
 *  Created on: 25-Sep-2020
 *      Author: anantha
 */

#include "Debug.h"

namespace Golem {

Debug::Debug() {
    // TODO Auto-generated constructor stub

}

Debug::~Debug() {
    // TODO Auto-generated destructor stub
}

void Debug::log(const std::string& str_){
    std::cout << str_ << std::endl;
}

void Debug::log(const std::string& str_1, const std::string& str_2){
    std::cout << str_1 << " " << str_2 << std::endl;
}

} /* namespace Golem */
