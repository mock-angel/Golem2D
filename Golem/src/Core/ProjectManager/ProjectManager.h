/*
 * ProjectManager.h
 *
 *  Created on: 17-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_PROJECTMANAGER_PROJECTMANAGER_H_
#define CORE_PROJECTMANAGER_PROJECTMANAGER_H_

#include <string>
#include <list>

#include "yaml-cpp/yaml.h"

namespace Golem {

class ProjectData{
public:
    ProjectData(const std::string& t_name, const std::string& t_dir){
        name = t_name;
        dir = t_dir;
    }

    std::string name;
    std::string dir;

};

class ProjectManager {

    std::list<ProjectData> m_projectList;
    std::string errorString;

    std::string projectListPath = "projects.list";
    YAML::Node projectList;

    //std::vector<YAML::Node> otherSubsidiary;

public:
    ProjectManager();
    virtual ~ProjectManager();

    void reloadList();
    bool addProject(const std::string& name, const std::string& dir);
    bool createProject(const std::string& name, const std::string& dir);

    void updateInFile();

    const std::string& getError(){
        return errorString;
    }
};



} /* namespace Golem */

#endif /* CORE_PROJECTMANAGER_PROJECTMANAGER_H_ */
