from sdl2 import *
import ctypes

import Golem

from OpenGL import GL, GLU
from OpenGL.GL import shaders
from OpenGL.arrays import vbo

import time

#from decorator import decorator


class Time(object):
    deltaTime = 0
    fixedDeltaTime = 0
    framesPerSecond = 0


class WindowOffLoad( object ):
    def __init__(self):
        pass
    
    def set_title(self, title_str):
        # TODO: check if its string and then change.
        title = title_str
        return self
    
    def set_size(self, size_tuple):
        size = size_tuple
        return self
    
class WindowBehaviour( object ):
    def __init__(self):
        self.m_mouseFocus = True
        self.m_keyboardFocus = True
        self.m_minimized = False
        self.m_closed = False
        
        self.m_shown = True
        
        self.m_width = 1
        self.m_height = 1
        self.m_size = (1, 1)
        
        self.m_sdlWindow = None
        
#        self.m_scene = None # TODO: Not Implemented yet.
        
        self.bgColor = 0, .7, .3, 1
        
    def isClosed(self):
        return self.m_closed

    def isMinimized(self):
        return self.m_minimized
    
    def getWindowId(self):
        return SDL_GetWindowID( self.m_window )
    
    @property
    def title(self):
        return self.m_title
        
    @title.setter
    def title(self, t_title):
    
        self.m_title = t_title
        
        SDL_SetWindowTitle(self.m_window, t_title);
        
        return self
        
    @property
    def size(self):
        return self.m_size
        
    @size.setter
    def size(self, t_size):
        self.m_size = t_size
        self.m_width = t_size[0]
        self.m_height = t_size[1]
    
    # Important Behaviours.
    def hide(self):
        """Hides the window and makes it disappear."""
        self.m_shown = False
        SDL_HideWindow( self.m_window )

    def show(self):
        """Unhides the window if hidden."""
        self.m_shown = True
        SDL_ShowWindow( self.m_window )

    def maximize(self):
        """Maximizes the window."""
        self.m_minimized = False
        SDL_MaximizeWindow( self.m_window )

    def minimise(self):
        """Minimises the window."""
        self.m_minimized = True
        SDL_MinimizeWindow( self.m_window )

    def restore(self):
        """Restores the window."""
        self.m_minimized = False
        SDL_RestoreWindow( self.m_window )

    def focus(self): # TODO: Test this.
        """Switches the focus to this window."""
        self.m_mouseFocus = self.m_keyboardFocus = True
        SDL_RaiseWindow(self.m_window)

    def SetBackgroundColor(self, r, g, b):
        self.bgColor = r, g, b
        
        
class WindowGLHandler( object ):
    def __init__(self):
        self.m_window = None
    
    def __del__(self):
        pass
    
#    def glCreateContext(self):
#        self.m_context = SDL_GL_CreateContext(self.m_window)
    
    def glSetViewport(self):
        GL.glViewport(0, 0, self.m_width, self.m_height);
        
    
    def glSetup(self):
        self.glCreateContext()
        self.glSetViewport()
        
    def glClear(self):
        GL.glClearColor(0.2, 0.3, 0.3, 0.0);
        
        GL.glClear(GL.GL_COLOR_BUFFER_BIT)# | GL.GL_DEPTH_BUFFER_BIT);
    
    def glSwap(self):
        SDL_GL_SwapWindow(self.m_window);
    
    def glClearAndSwap(self):
        GL.glClearColor(0.2, 0.3, 0.3, 1.0);
        GL.glClear(GL.GL_COLOR_BUFFER_BIT);
        
        SDL_GL_SwapWindow(self.m_window);

class WindowEvent( object ):
    def __init__(self):
        self.m_event = SDL_Event()
    
    def __del__(self):
        pass
    
    def _windowEvent(self, e):
        if( e.type == SDL_WINDOWEVENT ):
            if e.window.event == SDL_WINDOWEVENT_SHOWN:
                self.m_shown = True

            if e.window.event == SDL_WINDOWEVENT_HIDDEN:
                self.m_shown = False

            if e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED:
                #Get new dimensions and repaint.
                
                self.m_width = e.window.data1;
                self.m_height = e.window.data2;
                
                
                self.glSetViewport()
                #GL.glViewport(0, 0, self.m_width, self.m_height);
                
            if e.window.event == SDL_WINDOWEVENT_EXPOSED:
                pass
                
            if e.window.event == SDL_WINDOWEVENT_ENTER:
                self.m_mouseFocus = True

            if e.window.event == SDL_WINDOWEVENT_LEAVE:
                self.m_mouseFocus = False

            if e.window.event == SDL_WINDOWEVENT_FOCUS_GAINED:
                self.m_keyboardFocus = True

            if e.window.event == SDL_WINDOWEVENT_FOCUS_LOST:
                self.m_keyboardFocus = False

            if e.window.event == SDL_WINDOWEVENT_MINIMIZED:
                self.m_minimized = True

            if e.window.event == SDL_WINDOWEVENT_MAXIMIZED:
                self.m_minimized = False

            if e.window.event == SDL_WINDOWEVENT_RESTORED:
                self.m_minimized = False

            if e.window.event == SDL_WINDOWEVENT_CLOSE:

                self.hide()

                self.m_window = None;
#                self.m_renderer = None;
                self.m_closed = True;
                
    def _process_events(self):
        
        event = e = self.m_event;
        
        while (SDL_PollEvent(ctypes.byref(event)) != 0):
            #TODO: implement later.
#            if e.type == SDL_MOUSEMOTION:
#                self.m_mouse.x = e.motion.x
#                self.m_mouse.y = e.motion.y
                
            if( e.type == SDL_WINDOWEVENT ):
                self._windowEvent(e);
            
class WindowWorldHandler( object ):
    
    def __init__( self ):
        self.m_nodeManager = Golem.NodeManager()
        self.m_shaderManager = Golem.ShaderManager()
        
        pass
        
        
class Window( WindowBehaviour, WindowOffLoad, WindowGLHandler, WindowEvent, WindowWorldHandler ):
    DEFAULTPOS = SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED
    DEFAULTWINDOWFLAGS = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL
#    DEFAULTWINDOWFLAGS = SDL_WINDOW_OPENGL
#    DEFAULTRENDERFLAGS = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    
    instance = None
    
    def __init__(self, title = bytes(b"No Title"), width = 800, height = 600):
        """Initialize all the default variables for the window."""
        WindowOffLoad.__init__(self)
        WindowBehaviour.__init__(self)
        WindowGLHandler.__init__(self)
        WindowEvent.__init__(self)
        WindowWorldHandler.__init__(self)
        
        Window.instance = self
        
        self.m_title = title
        self.size = (width, height)
        
        self.m_screen_color = (45, 45, 45)
        
        self.m_context = None
        
        self.m_windowStartPos = Golem.Window.DEFAULTPOS
        self.m_windowFlags = Golem.Window.DEFAULTWINDOWFLAGS
#        self.m_rendererFLags = Golem.Window.DEFAULTRENDERFLAGS
        
#        Golem.Camera()
    def __del__(self):
#        SDL_DestroyRenderer(self.m_renderer);
        SDL_GL_DeleteContext(self.m_context)
        SDL_DestroyWindow(self.m_window);
        
        print("~Deleted Window")
        
    def Open(self):
        """Open the window, i.e. create it and show it to the user."""
        
        if SDL_Init(SDL_INIT_VIDEO) != 0:
            print(SDL_GetError())
            return -1
        
        self.m_window = window = SDL_CreateWindow(self.m_title,
                              self.m_windowStartPos[0], self.m_windowStartPos[1],
                              self.m_width, self.m_height, self.m_windowFlags)
        
        if not window:
            print(SDL_GetError())
            return -1

        
        print("Opened Window")
        
        self.hide()
        
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3)
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3)
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE)
        
        self.m_context = SDL_GL_CreateContext(self.m_window)
        
        SDL_GL_SetSwapInterval(1);
        
        self.glSetViewport()
        
        self.title = self.m_title
        
        self.show()
        
        self.start()
        self.game_loop()
        
    
    def _render_sequence(self):
        #render window stuff here.
        
        GL.glClearColor ( *self.bgColor );
        GL.glClear ( GL.GL_COLOR_BUFFER_BIT | GL.GL_DEPTH_BUFFER_BIT );
        
        # Application extra draws
        self.render()
        
        # node.render on all nodes.
        self.m_nodeManager.render_nodes()
        
    def game_loop(self):
        
        current_time = time.time()
        prev_time = time.time()
        
        total_time = 0
        
        fps_update_time = 0
        fps_count = 0
        
        while not self.m_closed:
            prev_time = current_time
            current_time = time.time()
            
            # Set Time.deltaTime
            Time.deltaTime = deltaTime = current_time - prev_time
            
            fps_count += 1
            
            total_time += deltaTime
            
            if(fps_update_time <= total_time):
                
                fps_update_time += 1
                
                Time.framesPerSecond = fps_count
                
                print(fps_count)
                
                fps_count = 0
            
            # Event calls
            self._process_events()
            
            # Update calls
            self.update()       #user function.
            self.m_nodeManager.update_nodes()   # update all nodes.
            
            # Render calls
            if self.m_shown and not self.m_minimized: self._render_sequence();
            SDL_GL_SwapWindow(self.m_window);
            
    #called when window starts.
    def start(self):
        pass
        
    def update(self):
        pass
    
    def render(self):
        pass
        
    def close(self):
        pass
