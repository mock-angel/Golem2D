from enum import Enum
import random

import Golem

class NodeManager:
    def __init__( self ):
        self.nodes_map = dict()
        
        self.__cache_values = list()
    def __del__( self ):
        pass
        
    def register_node( self, node ):
    
        self.nodes_map[node.m_rid] = node
    
    def discharge_node( self, node ):
        
        self.nodes_map.pop(node.m_rid, None)
    
    def update_nodes(self):
        
        self.__cache_values = values = self.nodes_map.values()
        
        for node in values:
        
            try: node.update()
            
            except: print("Node.update(): Exception occurred during node update.")
    
    def render_nodes(self):
        values = self.__cache_values
        
        for node in values:
        
            try: node.render()
            
            except: print("Node.render(): Exception occurred during node render.")
            
class NodeUserFunctions( object ):
    def __init__(self):
        pass
    
    def awake(self):
        pass
    
    def update(self):
        pass
    
    
class Node( NodeUserFunctions ):
    def __init__( self, t_window = None ):
        """If t_window is not passed, it registers itself with current window thats being executed."""
        
        NodeUserFunctions.__init__(self)
        
        self.m_name = "Empty Node"
        self.m_rid = -1
        self.m_nodes = {}
        
        self.m_window = Golem.Window.instance if(t_window == None) else t_window
        
        self._register()
        
    def __del__( self ):
        pass
    
    def _register( self ):
    
        self.m_rid = random.randrange(10000000, 99999999)
        
        #test
#        if(NodeManager.instance == None): NodeManager()
            
        self.m_window.m_nodeManager.register_node( self )
        
    def add_child_node( self, node):
        self.m_nodes[node.m_name] = node
    
    def remove_child_node( self, node):
        self.m_nodes.pop(node.m_name, None)
    
    def delete_child_node( self, node):
        node = self.m_nodes.pop(node.m_name, None)
        
        if (node != None): del node
            
    def get_rid(self):
        return self.m_rid
    
    
    
    
class Callback:
    def __init__(self, callback, *params):
        self.m_callback = callback
        self.m_params = params
        
        self.meta = ""
        
    def __call__(self):
        self.m_callback(*self.m_params)
    
class CallbacksContainer:
    def __init__(self):
        self.m_callbacks = []
    
    def __add__(self, other):
        self.m_callbacks.append(Callback(other))
        return self
        
    def __sub__(self, callback):
        return self
    
    def __call__(self):
        for callback in self.m_callbacks:
            callback()
    
    def add_callback(self, callback):
        """Callback parameter should be of the type/derived-from Callback."""
        
        self.m_callbacks.append(callback)
        
    def remove_callback(self, callback):
        """Callback parameter should be of the type Callback."""
        
        self.m_callbacks.remove(callback)
    
    def execute(self):
        for callback in self.m_callbacks:
            try: callback()
                
            except: print("Exception occurred")
                
class ButtonScene( Node ):
    def __init__(self):
        Node.__init__(self)
        
        self.m_disabled = False
        
        self.m_callbacks = {
            "OnClicked" : CallbacksContainer()
        }
        
    def __del__(self):
        pass
    
    def OnClicked(self):
        self.m_callbacks["OnClicked"].execute()


class Camera( Node ):
    class Projection(Enum):
        PROJECTION_ORTHOGONAL = 0
        PROJECTION_PERSPECTIVE = 1
        
    def __init__( self ):
        Node.__init__(self)
        
        self.current = False
        
        self.far = 100
        self.fov = 70
        
        self.near = 0.05
        self.size = 1.0
    
        self.projection = Camera.Projection.PROJECTION_PERSPECTIVE
    
    def set_current(self, value):
        self.current = value

