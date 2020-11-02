/*
 * ShaderData.h
 *
 *  Created on: 27-Sep-2020
 *      Author: anantha
 */

#ifndef GRAPHICS_SHADER_SHADERDATA_H_
#define GRAPHICS_SHADER_SHADERDATA_H_

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL2/SDL_opengl.h>

#include <string>
#include <list>
#include <array>

namespace Golem {

struct ShaderPiece{
    GLenum shaderType = 0;
    std::string content;

    bool hasContent = false;

    //ShaderPiece(){}
    ShaderPiece(std::string& t_shaderContent){
        setContent(t_shaderContent);
    }

    void setContent(std::string& t_content){
        content = t_content;
        hasContent = true;
    }
};

class ShaderData {
    std::string m_path;
    std::list<ShaderPiece> m_dataList;

public:
    ShaderData();
    ShaderData(std::string& t_path){
        setPath(t_path);
    }
    virtual ~ShaderData();

    //void loadContents();
    void addPiece(GLenum shaderType, std::string& shaderContent){;
        m_dataList.push_back(ShaderPiece(shaderContent));
    }

    void setPath(std::string& t_path){m_path = t_path;}
    std::string getPath(){return m_path;}

    std::list<ShaderPiece>& getContentList() {
        return m_dataList;
    }
};

} /* namespace Golem */

#endif /* GRAPHICS_SHADER_SHADERDATA_H_ */
