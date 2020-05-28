import sys
#sys.path.insert(0, '../engineGLSDL2')
#import PycCleanup
import Golem
#import config
from OpenGL.GL import *
import sys
import numpy  

class ApplicationTest(Golem.Window):
    def __init__(self):
        Golem.Window.__init__(self)
    
    
    def start(self):
        myShader = Golem.Shader("testVShader", "testFShader")
        #myShader.use()
        
        self.myShader = myShader
        
#        self.vertices = vertices = [
#             # positions         # colors
#             0.5, -0.5, 0.0,  1.0, 0.0, 0.0,  # bottom right
#            -0.5, -0.5, 0.0,  0.0, 1.0, 0.0,  # bottom left
#             0.0,  0.5, 0.0,  0.0, 0.0, 1.0   # top 
#        ]
        self.vertices = vertices = [
             # positions         # colors
             0.5, -0.5, 0.0,#  1.0, 0.0, 0.0,  # bottom right
            -0.5, -0.5, 0.0,#  0.0, 1.0, 0.0,  # bottom left
             0.0,  0.5, 0.0,#  0.0, 0.0, 1.0   # top 
        ]
        
        self.colors = colors = [
            # colors
            1.0, 0.0, 0.0,  # bottom right
            0.0, 1.0, 0.0,  # bottom left
            0.0, 0.0, 1.0   # top 
        ]
        
        self.vertices = vertices = numpy.array(vertices, dtype=numpy.float32) 
        self.colors = colors = numpy.array(colors, dtype=numpy.float32)
        
        print(vertices)
        VBO, VAO = 0, 0
        
        VAO = glGenVertexArrays(1);
        VBO = glGenBuffers(1);
        VBO2 = glGenBuffers(1);
        
        # bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
        glBindVertexArray(VAO);
        
        float32size = sys.getsizeof(numpy.float32())
        
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices, GL_STATIC_DRAW);
        
        
        
        # position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, None);
        glEnableVertexAttribArray(0);
        
        glBindBuffer(GL_ARRAY_BUFFER, VBO2);
        glBufferData(GL_ARRAY_BUFFER, colors, GL_STATIC_DRAW);
        # color attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, None);
        glEnableVertexAttribArray(1);
        
        self.VBO, self.VAO = VBO, VAO
        
    def render(self):
        ourShader = self.myShader
        
        ourShader.use();
        glBindVertexArray(self.VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glUseProgram(0);
        
if __name__ == "__main__":
    app = Golem.Application()
    window = app.CreateWindow("PyGolem", window = ApplicationTest, size = (200, 300))\
#                  .setBackgroundColor(*config.SCREEN_COLOR) window = config.main_app,
    
    
#    app.Start()
