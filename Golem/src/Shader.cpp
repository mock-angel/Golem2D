/*
 * Shader.cpp
 *
 *  Created on: 02-Jun-2020
 *      Author: anantha
 */

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL2/SDL_opengl.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Shader.h"
#include "Debug.h"

namespace Golem {

Shader::Shader(const char*  vertexPath, const char* fragmentPath, const char* geometryPath){
    std::cout << "Shader::Shader Construct Shader"<<std::endl;
    unsigned int vertex, fragment, geometry;
    vertex = loadShaderFromFile(vertexPath, GL_VERTEX_SHADER);
    fragment = loadShaderFromFile(fragmentPath, GL_FRAGMENT_SHADER);
    if(geometryPath!=nullptr) geometry = loadShaderFromFile(geometryPath, GL_GEOMETRY_SHADER);
    // shader Program
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    if(geometryPath!=nullptr) glAttachShader(ID, geometry);

    glLinkProgram(ID);
    glDeleteShader(vertex);
    glDeleteShader(fragment);
    if(geometryPath != nullptr) glDeleteShader(geometry);
    checkCompileErrors(ID, "PROGRAM");
    // delete the shaders as they're linked into our program now and no longer necessary

    Debug::log(std::string("its ") + std::to_string(ID));
    isCompiled = true;
}

Shader::Shader(){

}

Shader::Shader(ShaderData t_shaderData){
    ID = glCreateProgram();
    std::list<unsigned int> listOfCreatedShaders;
    std::list<ShaderPiece> contentList = t_shaderData.getContentList();

    for( ShaderPiece& shaderPiece : contentList ){
        Debug::log(shaderPiece.content);
        unsigned int shader = loadShaderFromData(shaderPiece.content, shaderPiece.shaderType);
        glAttachShader(ID, shader);
        checkCompileErrors(shader, "SHADER");
        listOfCreatedShaders.push_back(shader);
    }
    glLinkProgram(ID);
    for(unsigned int shader: listOfCreatedShaders)
        glDeleteShader(shader);
    checkCompileErrors(ID, "PROGRAM");
}

Shader::~Shader() {
    // TODO Auto-generated destructor stub
}

unsigned int Shader::loadShaderFromFile(const char* shaderPath, GLenum shaderType){
    std::string shaderCode;
    std::ifstream shaderFile;
    shaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        // open files
        shaderFile.open(shaderPath);
        std::stringstream shaderStream;
        // read file's buffer contents into streams
        shaderStream << shaderFile.rdbuf();
        // close file handlers
        shaderFile.close();
        // convert stream into string
        shaderCode   = shaderStream.str();

    }
    catch (std::ifstream::failure& e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        return -1;
    }
    std::cout << "Construct Shader"<<std::endl;
    const char* cShaderCode = shaderCode.c_str();
    //shader creation.
    unsigned int shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &cShaderCode, NULL);
    glCompileShader(shader);
    checkCompileErrors(shader, "SHADER");

    return shader;
}

unsigned int Shader::loadShaderFromData(std::string& shaderCode, GLenum shaderType){

    const char* cShaderCode = shaderCode.c_str();
    //shader creation.
    unsigned int shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &cShaderCode, NULL);
    glCompileShader(shader);
    checkCompileErrors(shader, "SHADER");

    return shader;
}

void attatchShader(std::string shaderPath, GLenum shaderType){

}

void Shader::use(){
    if(isCompiled) glUseProgram(ID);
    else Debug::log(std::string("ERROR::SHADER_USE_ERROR in Shader::use() :Failed to use uncompiled shader program ") + std::to_string(ID));
}

// utility uniform functions
// ------------------------------------------------------------------------
void Shader::setBool(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}
// ------------------------------------------------------------------------
void Shader::setInt(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
// ------------------------------------------------------------------------
void Shader::setFloat(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}
// ------------------------------------------------------------------------
void Shader::setVec2(const std::string &name, const glm::vec2 &value) const
{
    glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}
void Shader::setVec2(const std::string &name, float x, float y) const
{
    glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y);
}
// ------------------------------------------------------------------------
void Shader::setVec3(const std::string &name, const glm::vec3 &value) const
{
    glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}
void Shader::setVec3(const std::string &name, float x, float y, float z) const
{
    glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
}
// ------------------------------------------------------------------------
void Shader::setVec4(const std::string &name, const glm::vec4 &value) const
{
    glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}
void Shader::setVec4(const std::string &name, float x, float y, float z, float w)
{
    glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w);
}
// ------------------------------------------------------------------------
void Shader::setMat2(const std::string &name, const glm::mat2 &mat) const
{
    glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
// ------------------------------------------------------------------------
void Shader::setMat3(const std::string &name, const glm::mat3 &mat) const
{
    glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
// ------------------------------------------------------------------------
void Shader::setMat4(const std::string &name, const glm::mat4 &mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}


// utility function for checking shader compilation/linking errors.
// ------------------------------------------------------------------------
bool Shader::checkCompileErrors(unsigned int shader, std::string type)
{
    int success;
    char infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
    return success;
}

} /* namespace Golem */
