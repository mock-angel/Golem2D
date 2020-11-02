/*
 * ShaderLoader.h
 *
 *  Created on: 27-Sep-2020
 *      Author: anantha
 */

#ifndef GRAPHICS_SHADER_SHADERLOADER_H_
#define GRAPHICS_SHADER_SHADERLOADER_H_

#include <map>
#include <string>
#include <vector>

#include "Shader.h"
#include "ShaderInfo.h"
#include "rapidjson/document.h"     // rapidjson's DOM-style API
#include "rapidjson/prettywriter.h" // for stringify JSON

namespace Golem {

class ShaderLoader {


public:
    ShaderLoader();
    virtual ~ShaderLoader();

    void updateShaderLocations();
    //void loadAllShaders();

    void loadShaders();
    Shader getShader(std::string shadername){return m_shaderdata[shadername].getShader();}

private:
    std::map<std::string, ShaderInfo> m_shaderdata;
    std::vector<std::string> shaderLocations;
};

} /* namespace Golem */

#endif /* GRAPHICS_SHADER_SHADERLOADER_H_ */
