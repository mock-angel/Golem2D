/*
 * Mono.h
 *
 *  Created on: 16-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_MONO_H_
#define CORE_MONO_H_

#include <string>

#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>

namespace Golem {

class Mono {
    MonoDomain *domain;
    MonoAssembly *assembly;

    std::string m_domainName;

public:
    Mono(const char* t_domainName, const char* t_exeDir);
    ~Mono();
};

} /* namespace Golem */

#endif /* CORE_MONO_H_ */
