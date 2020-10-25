/*
 * ShaderLoader.h
 *
 *  Created on: 27-Sep-2020
 *      Author: anantha
 */

#ifndef SHADERLOADER_H_
#define SHADERLOADER_H_

#include <map>
#include <string>
#include <vector>

#include "Shader.h"
#include "ShaderInfo.h"

#include "rapidjson/document.h"     // rapidjson's DOM-style API
#include "rapidjson/prettywriter.h" // for stringify JSON

namespace Golem {

class ShaderLoader {

    std::map<std::string, ShaderInfo> m_shaderdata;
    std::vector<std::string> shaderLocations;
public:
    ShaderLoader();
    virtual ~ShaderLoader();

    void updateShaderLocations();
    //void loadAllShaders();

    void loadShaders();
    Shader getShader(std::string shadername){return m_shaderdata[shadername].getShader();}
};

} /* namespace Golem */

#endif /* SHADERLOADER_H_ */
