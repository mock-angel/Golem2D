/*
 * Shader.h
 *
 *  Created on: 02-Jun-2020
 *      Author: anantha
 */

#ifndef SHADER_H_
#define SHADER_H_

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glm/glm.hpp>
#include <SDL2/SDL_opengl.h>

#include <string>

#include "ShaderData.h"

namespace Golem {

class Shader {
public:
    //Shader(const char* vertexPath, const char* fragmentPath);
    Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr);
    //Shader(std::string shaderPath);
    Shader();
    Shader(ShaderData t_shaderData);

    Shader(const Shader& shader){
        ID = shader.getID();
        isCompiled = shader.isCompiled;
    }

    virtual ~Shader();

    unsigned int getID() const {return ID;}

    unsigned int loadShaderFromFile(const char*  shaderPath, GLenum shaderType);
    unsigned int loadShaderFromData(std::string& shaderCode, GLenum shaderType);

    /*
    void loadFragmentShader(std::string fragmentPath);
    void loadShader(std::string shaderPath, GLenum shaderType);
    */

    void use();

    // utility uniform functions
    // ------------------------------------------------------------------------
    void setBool(const std::string &name, bool value) const;
    // ------------------------------------------------------------------------
    void setInt(const std::string &name, int value) const;
    // ------------------------------------------------------------------------
    void setFloat(const std::string &name, float value) const;
    // ------------------------------------------------------------------------
    void setVec2(const std::string &name, const glm::vec2 &value) const;
    void setVec2(const std::string &name, float x, float y) const;
    // ------------------------------------------------------------------------
    void setVec3(const std::string &name, const glm::vec3 &value) const;
    void setVec3(const std::string &name, float x, float y, float z) const;
    // ------------------------------------------------------------------------
    void setVec4(const std::string &name, const glm::vec4 &value) const;
    void setVec4(const std::string &name, float x, float y, float z, float w);
    // ------------------------------------------------------------------------
    void setMat2(const std::string &name, const glm::mat2 &mat) const;
    // ------------------------------------------------------------------------
    void setMat3(const std::string &name, const glm::mat3 &mat) const;
    // ------------------------------------------------------------------------
    void setMat4(const std::string &name, const glm::mat4 &mat) const;

private:
    unsigned int ID;
    bool isCompiled = false;

    bool checkCompileErrors(unsigned int shader, std::string type);

};

} /* namespace Golem */

#endif /* SHADER_H_ */
