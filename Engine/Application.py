import weakref

import Golem

#class WindowSettings():
#    def __init__(self):
#        self.Name = ""
#        self.Size = (592, 460)

class Application():
    _window = None
    def __new__(self):
        if (Application._window != None):
            print("Application Allready Exists. Cannot create duplicate application.");
        else: window = self
        
        return weakref.proxy(self);
            
    def __del__(self):
        pass
    
    def CreateWindow(self, title = "", size = (592, 460)):
        pass
    
    def Start(self):
        pass
    
    def Run(self):
#        self.loadModules()
#        self.loadScripts()
#        self.startEngine()
#        self.runEngine()
        pass
    
    def processEvents(self):
        pass
#        e = event = SDL_Event()
#        
#        while len(self.m_windowsMap)!=0 and SDL_WaitEvent(ctypes.byref(event)) != 0:
#            pass
    
    def ApplicationLoop(self):
        
        while(not self.closed):
            processEvents();
            
            self.Quit();
            
    def Quit(self):
        self.closed = True
    
