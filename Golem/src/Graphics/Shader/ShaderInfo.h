/*
 * ShaderInfo.h
 *
 *  Created on: 01-Oct-2020
 *      Author: anantha
 */

#ifndef GRAPHICS_SHADER_SHADERINFO_H_
#define GRAPHICS_SHADER_SHADERINFO_H_

#include <string>

#include "Shader.h"

namespace Golem {

class ShaderInfo {
    std::string m_name;
    std::string m_path;
    Shader m_shader;

public:
    ShaderInfo();
    ShaderInfo(std::string& t_name, std::string& t_path, Shader t_shader){
        setName(t_name);
        setPath(t_path);
        setShader(t_shader);
    }
    ShaderInfo(ShaderInfo& shaderInfo){
        setName(shaderInfo.getName());
        setPath(shaderInfo.getPath());
        setShader(shaderInfo.getShader());
    }
    virtual ~ShaderInfo();

    void setName(std::string t_name){m_name = t_name;}
    void setPath(std::string t_path){m_path = t_path;}
    void setShader(Shader t_shader){m_shader = t_shader;}

    std::string getName(){return m_name;}
    std::string getPath(){return m_path;}
    Shader getShader(){return m_shader;}
};

} /* namespace Golem */

#endif /* GRAPHICS_SHADER_SHADERINFO_H_ */
