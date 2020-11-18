//============================================================================
// Name        : ttt.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>

#include <mono/metadata/object.h>
#include <mono/metadata/environment.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/debug-helpers.h>
#include <mono/metadata/mono-config.h>


static MonoObject*
create_object (MonoDomain *domain, MonoImage *image)
{
    MonoClass *klass;
    MonoObject *obj;

    klass = mono_class_from_name (image, "MonoEngine", "MonoEngineClass");
    if (!klass) {
        fprintf (stderr, "Can't find MyType in assembly %s\n", mono_image_get_filename (image));
        exit (1);
    }

    obj = mono_object_new (domain, klass);
    /* mono_object_new () only allocates the storage:
     * it doesn't run any constructor. Tell the runtime to run
     * the default argumentless constructor.
     */
    mono_runtime_object_init (obj);

    //access_valuetype_field (obj);
    //access_reference_field (obj);

    //call_methods (obj);
    //more_methods (domain);
    return obj;
}



int main() {

    std::string scriptPath("../MonoEngine");
    //std::string command = "mcs " + scriptPath + " -target:library";
    std::string command = "cd " + scriptPath + " && dotnet build --no-restore";

    system(command.c_str());
    //command = "cd " + scriptPath + "";

    //mono_set_dirs("/usr/lib/", "/etc/mono/");
    MonoDomain* domain = mono_jit_init ("MonoEngine");
    const char* t_exeDir = "../MonoEngine/bin/Debug/netcoreapp3.1/MonoEngine.dll";
    if (!domain) exit (1);

    MonoAssembly* assembly = mono_domain_assembly_open (domain, t_exeDir);
    //mono_jit_init_version ("myapp", "v4.0.30319");



    if (!assembly)
            exit (2);
    mono_config_parse (NULL);

        char *argv[] = {
            (char*)t_exeDir,
            (char*)t_exeDir,
            NULL
        };


    mono_jit_exec (domain, assembly, 1, argv+1);
    MonoImage* image = mono_assembly_get_image (assembly);
    create_object (domain, image);


    //cout << "!!!Hello Wor77ld!!!" << endl; // prints !!!Hello World!!!


    mono_jit_cleanup (domain);
	return 1;
}
