/*
 * Mono.cpp
 *
 *  Created on: 16-Nov-2020
 *      Author: anantha
 */

#include "Mono.h"

#include <mono/metadata/object.h>
#include <mono/metadata/environment.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/debug-helpers.h>
#include <mono/metadata/mono-config.h>
#include <string>
#include <stdlib.h>

namespace Golem {


/*
static void main_function (MonoDomain *domain, const char *file, int argc, char **argv)
{
    MonoAssembly *assembly;

    /* Loading an assembly makes the runtime setup everything
     * needed to execute it. If we're just interested in the metadata
     * we'd use mono_image_load (), instead and we'd get a MonoImage*.
     *
    assembly = mono_domain_assembly_open (domain, file);
    if (!assembly)
        exit (2);
    /*
     * mono_jit_exec() will run the Main() method in the assembly.
     * The return value needs to be looked up from
     * System.Environment.ExitCode.
     *
    //mono_jit_exec (domain, assembly, argc, argv);

    //create_object (domain, mono_assembly_get_image (assembly));
}*/


Mono::Mono(const char* t_domainName, const char* t_exeDir) {
    // TODO Auto-generated constructor stub
    m_domainName = t_domainName;

    domain = mono_jit_init (m_domainName.c_str());

    assembly = mono_domain_assembly_open (domain, t_exeDir);

    if (!assembly)//Error
    ;

    mono_config_parse (NULL);

    char *argv[] = {
        (char*)t_exeDir,
        (char*)t_exeDir,
        NULL
    };


    mono_jit_exec (domain, assembly, 1, argv+1);
}

Mono::~Mono() {
    // TODO Auto-generated destructor stub
    mono_jit_cleanup (domain);

}

} /* namespace Golem */
