/*
 * ScriptingEngine.h
 *
 *  Created on: 16-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_SCRIPTINGENGINE_SCRIPTINGENGINE_H_
#define CORE_SCRIPTINGENGINE_SCRIPTINGENGINE_H_

#include <memory>

namespace Golem {

class Mono;

class ScriptingEngine {
public:
    ScriptingEngine();
    virtual ~ScriptingEngine();

private:
    std::shared_ptr<Mono> m_monoEngine;
};

} /* namespace Golem */

#endif /* CORE_SCRIPTINGENGINE_SCRIPTINGENGINE_H_ */
