import sys
#sys.path.insert(0, '../engineGLSDL2')
#import PycCleanup
import Golem
#import config

class ApplicationTest(Golem.Window):
    def __init__(self):
        Golem.Window.__init__(self)
        
        
        
if __name__ == "__main__":
    app = Golem.Application()
    window = app.CreateWindow("PyGolem", window = ApplicationTest, size = (200, 300))\
#                  .setBackgroundColor(*config.SCREEN_COLOR) window = config.main_app,
    
    
#    app.Start()
