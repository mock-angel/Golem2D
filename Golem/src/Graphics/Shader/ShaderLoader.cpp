/*
 * ShaderLoader.cpp
 *
 *  Created on: 27-Sep-2020
 *      Author: anantha
 */

#include "ShaderLoader.h"

#include <filesystem>
#include <iterator>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/error/en.h"

#include <nlohmann/json.hpp>
#include "../../Debug.h"
#include "ShaderData.h"
#include "ShaderInfo.h"

using namespace rapidjson;
using namespace nlohmann;
//using json = nlohmann::json;

namespace Golem {

/*
struct path_leaf_string
{
    std::string operator()(const std::filesystem::directory_entry& entry) const
    {
        return entry.path().leaf().string();
    }
};*/

void read_directory(const std::string& name, const std::string& ext, std::vector<std::string>& paths)
{
    //std::filesystem::path p(name);
    //std::filesystem::directory_iterator start(p);
    //std::filesystem::directory_iterator end;
    //std::transform(start, end, std::back_inserter(v), path_leaf_string());
    for(auto& p: std::filesystem::recursive_directory_iterator(name)){
        /* Get file name. */
        std::string fullpath = p.path();
        std::size_t found = fullpath.find_last_of("/\\");
        //std::string path = fullpath.substr(0, found);
        //std::string filename = fullpath.substr(found + 1);

        /* Validate Extension. */
        std::size_t periodfound = fullpath.find_last_of(".");
        //std::string filenameraw = fullpath.substr(0, periodfound);
        std::string fileext = fullpath.substr(periodfound + 1);

        if(fileext == ext){
            /* This file can be used. */
            paths.push_back(fullpath);
            std::cout << true << std::endl;
        }
        //std::cout << p.path() << " " << path << " " << filename << " " << filenameraw << std::endl;
    }
}

ShaderLoader::ShaderLoader() {
    // TODO Auto-generated constructor stub

}

ShaderLoader::~ShaderLoader() {
    // TODO Auto-generated destructor stub
}

void ShaderLoader::updateShaderLocations(){
    shaderLocations.clear();
    read_directory("src/Res/Shaders", "shader", shaderLocations);
}

void loadFile(std::filesystem::path const& path){

}

auto read_file(const std::string& path) -> std::string {
    constexpr auto read_size = std::size_t{4096};
    auto stream = std::ifstream{path};
    stream.exceptions(std::ios_base::badbit);

    auto out = std::string{};
    auto buf = std::string(read_size, '\0');
    while (stream.read(& buf[0], read_size)) {
        out.append(buf, 0, stream.gcount());
    }
    out.append(buf, 0, stream.gcount());
    return out;
}

bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

void replace_all(std::string& str, const std::string& from, const std::string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

void constructShaderData(){

}

void ShaderLoader::loadShaders(){
    updateShaderLocations();

    for(std::string& path: shaderLocations){
        //std::string fullpath = p.path();
        std::size_t found = path.find_last_of("/\\");
        //std::string path = fullpath.substr(0, found);
        std::string filename = path.substr(found + 1);

        /* Validate Extension. */
        std::size_t periodfound = filename.find_last_of(".");
        std::string filenameraw = filename.substr(0, periodfound);

        /*
        Code to get shader source goes here...
        */
        //Debug::log("FILE CONTENTS: " + read_file(path));

        std::string jsonString = read_file(path);


        replace_all(jsonString, "\n", "");
        replace_all(jsonString, "\t", "");
        json j = json::parse(jsonString.c_str());

        const std::string& vertexContent = j["v_shader"];
        const std::string& fragmentContent = j["f_shader"];
        const std::string& geometryContent = j["g_shader"];

        Shader shader(vertexContent.c_str(), fragmentContent.c_str());
        ShaderInfo shaderInfo(filename, path, shader);

        m_shaderdata[filenameraw] = shaderInfo;
    }
}



} /* namespace Golem */
