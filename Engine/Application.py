import weakref

import Golem

#class WindowSettings():
#    def __init__(self):
#        self.Name = ""
#        self.Size = (592, 460)

class Application:
    _app = None
    def __new__(self):
        instance = object.__new__(self)
        
        if (Application._app != None):
            return weakref.proxy(instance);
            raise (RuntimeError, "Count not create Application. Application Allready Exists." )
        else: 
            _app = self
            return instance
            
    
    def __init__(self):
        self.m_windowsMap = {}
        
    def __del__(self):
        pass
    
    def CreateWindow(self, title = "", window = None , size = (592, 460)):
        new_window = Golem.Window() if not window else window()
        new_window.size = size
        new_window.Open()
        
        self.m_windowsMap[new_window.getWindowId()] = new_window


######## Dont use this for single window ########
#    def Start(self):
#        pass
    
#    def Run(self):
#        self.loadModules()
#        self.loadScripts()
#        self.startEngine()
#        self.runEngine()
#        pass
    
#    def processEvents(self):
#        pass
#        e = event = SDL_Event()
#        
#        while len(self.m_windowsMap)!=0 and SDL_WaitEvent(ctypes.byref(event)) != 0:
#            pass
    
#    def ApplicationLoop(self):
#        
#        while(not self.closed):
#            processEvents();
#            
#            self.Quit();
            
#    def Quit(self):
#        self.closed = True
    
