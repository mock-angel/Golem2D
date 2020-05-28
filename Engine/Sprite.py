
import Golem

class Sprite(Golem.Node):
    def __init__(self):
        self.m_shader = None
        self.m_texture = None
    
    @property
    def shader(self):
        return self.m_shader
    
    @shader.setter
    def shader(self, value):
        self.m_shader = value
    
    @property
    def texture(self):
        return self.m_texture
    
    @texture.setter
    def texture(self, value):
        self.m_texture = value
    
    def render(self):
        if(self.m_shader != None) self.m_shader.use()
    
