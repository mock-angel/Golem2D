/*
 * ScriptingEngine.cpp
 *
 *  Created on: 16-Nov-2020
 *      Author: anantha
 */

#include "ScriptingEngine.h"
#include "Mono/Mono.h"

namespace Golem {

ScriptingEngine::ScriptingEngine() {
    // TODO Auto-generated constructor stub
    m_monoEngine = std::shared_ptr<Mono>(new Mono("MonoEngine", "../../MonoEngine/bin/Debug/netcoreapp3.1/MonoEngine"));
}

ScriptingEngine::~ScriptingEngine() {
    // TODO Auto-generated destructor stub
}

} /* namespace Golem */
