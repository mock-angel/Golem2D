import sys
#sys.path.insert(0, '../engineGLSDL2')
#import PycCleanup
import Golem
#import config

if __name__ == "__main__":
    app = Golem.Application()
    window = app.CreateWindow("PyGolem",  size = (200, 300))\
#                  .setBackgroundColor(*config.SCREEN_COLOR) window = config.main_app,
    
    
    app.Start()
