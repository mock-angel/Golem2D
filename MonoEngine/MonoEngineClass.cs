using System;
using GolemEngine;
using GolemEngine.CoreModule;

namespace MonoEngine
{
    public class MonoEngineClass
    {
        MonoEngineClass(){
            Console.WriteLine("Created MonoEngineClass");
        }

        ~MonoEngineClass(){
            Console.WriteLine("Destroyed MonoEngineClass");
        }
    }

}