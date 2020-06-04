from OpenGL import GL, GLU
#from OpenGL.GL import shaders
#from OpenGL.arrays import vbo

from OpenGL.GL import *
import ctypes

import random

import Golem

class Shader:
    def __init__(self, vertexPath :str, fragmentPath :str):
        self.ID = -1
        
        vertexCode = ""
        fragmentCode = ""
        
        with open(vertexPath, 'r') as f:
            vertexCode = f.read()
        
        with open(fragmentPath, 'r') as f:
            fragmentCode = f.read()
        
        self.vertexCode = vertexCode
        self.fragmentCode = fragmentCode
        
        self.vertexCode = vertexCode.encode()
        self.fragmentCode = fragmentCode.encode()
        
#        print(self.vertexCode)
        
        self.compile()
#        self.use()
        
        self.m_window = Golem.Window.instance# if(t_window == None) else t_window
        
        self.__register()
        
    def __register(self):
        self.m_sid = random.randrange(100000, 999999)
        self.m_window.m_shaderManager.register_shader( self )
        
    def compile(self):
    
        vShaderCode = self.vertexCode
        fShaderCode = self.fragmentCode
        
        # compile shaders
        vertex, fragment = (0, 0)
        success = False
        infoLog = ""
        
        vertex = self.compileShader(vShaderCode, GL_VERTEX_SHADER)
        fragment = self.compileShader(fShaderCode, GL_FRAGMENT_SHADER)
#        # vertex Shader
#        vertex = glCreateShader(GL_VERTEX_SHADER);
#        glShaderSource(vertex, vShaderCode);
#        glCompileShader(vertex);
#        
##        glGetShaderiv(vertex, GL_COMPILE_STATUS, success);
#        print(glGetShaderiv(vertex, GL_COMPILE_STATUS))
#        print(success)
#        
#        # print compile errors if any
#        if not glGetShaderiv(vertex, GL_COMPILE_STATUS):
#            glGetShaderInfoLog(vertex, 512, None, infoLog);
#            print("ERROR::SHADER::VERTEX::COMPILATION_FAILED%s", infoLog)
#        else: print("SHADER compiled successfully")
#        
#        # fragment Shader
#        fragment = glCreateShader(GL_VERTEX_SHADER);
#        
#        
        # shader Program
        ID = glCreateProgram();
        glAttachShader(ID, vertex);
        glAttachShader(ID, fragment);
        glLinkProgram(ID);
        
        glDeleteShader(vertex);
        glDeleteShader(fragment);
        self.ID = ID
        
        del self.vertexCode
        del self.fragmentCode
        
    def compileShader(self, source, shaderType):
        """
        Compile shader source of given type
            source -- GLSL source-code for the shader
        shaderType -- GLenum GL_VERTEX_SHADER, GL_FRAGMENT_SHADER, etc,
            returns GLuint compiled shader reference
        raises RuntimeError when a compilation failure occurs
        """
        if isinstance(source, str):
            source = [source]
        elif isinstance(source, bytes):
            source = [source.decode('utf-8')]

        shader = GL.glCreateShader(shaderType)
        GL.glShaderSource(shader, source)
        GL.glCompileShader(shader)
        result = GL.glGetShaderiv(shader, GL.GL_COMPILE_STATUS)
        if not(result):
            # TODO: this will be wrong if the user has
            # disabled traditional unpacking array support.
            raise RuntimeError(
                """Shader compile failure (%s): %s""" % (
                    result,
                    GL.glGetShaderInfoLog(shader),
                ),
                source,
                shaderType,
            )
        return shader 
        
    def __del__(self):
        pass
    
    def setBool(self, name :str, value :bool):
    
        glUniform1i(glGetUniformLocation(self.ID, name), int(value));
        
    def setInt(self, name :str, value :int):
    
        glUniform1i(glGetUniformLocation(self.ID, name), value);
        
    def setFloat(self, name :str, value :float):
    
        glUniform1f(glGetUniformLocation(self.ID, name), value); 
    
    def setUniform(self, name :str, glFunction, *params):
        glFunction(glGetUniformLocation(self.ID, name), *params);
        
    def use(self):
        glUseProgram(self.ID);
        
#        self.setUniform("ourColor", glUniform4f, 1, 0, 0, 0);
        
class ShaderManager:
    def __init__(self):
        self.m_shaders = dict()
        
    def get_shader(self, sid):
        
        shaders = self.m_shaders
        
        if sid in shaders:
            return shaders[sid]
            
        else: return None
        
    def register_shader(self, shader):
        self.m_shaders[shader.m_sid] = shader
        
