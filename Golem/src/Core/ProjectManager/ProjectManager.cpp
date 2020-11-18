/*
 * ProjectManager.cpp
 *
 *  Created on: 17-Nov-2020
 *      Author: anantha
 */

#include "ProjectManager.h"

#include <iostream>

#include <fstream>
#include <map>
#include <string>

#include "yaml-cpp/yaml.h"
#include "Debug.h"

namespace Golem {

ProjectManager::ProjectManager() {
    // TODO Auto-generated constructor stub
    //YAML::Node config = YAML::LoadFile("engine.config");
    //reloadList();
}

ProjectManager::~ProjectManager() {
    // TODO Auto-generated destructor stub
}

void ProjectManager::reloadList(){
    std::ifstream fin(projectListPath);
    std::string fullstr, linestr;

    while ( getline (fin, linestr) )
        fullstr += linestr+'\n';

    fin.close();

    projectList = YAML::LoadFile(projectListPath);

    //otherSubsidiary = YAML::LoadAllFromFile("projects2.list");

    m_projectList.clear();

    for(auto yamlIt : projectList){
        std::string name = yamlIt.first.as<std::string>();
        std::string dir = yamlIt.second.as<std::string>();

        m_projectList.emplace_back(name, dir);
    }
}

bool ProjectManager::addProject(const std::string& name, const std::string& dir){
    m_projectList.emplace_back(name, dir);

    updateInFile();
    return true;
}

bool ProjectManager::createProject(const std::string& name, const std::string& dir){
    m_projectList.emplace_back(name, dir);

    updateInFile();
    return true;
}

void ProjectManager::updateInFile(){
    std::ofstream fout(projectListPath);
    fout<<projectList;
}

} /* namespace Golem */
