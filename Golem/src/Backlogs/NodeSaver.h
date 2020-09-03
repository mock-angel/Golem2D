/*
 * NodeSaver.h
 *
 *  Created on: 20-Aug-2020
 *      Author: anantha
 */

#ifndef NODESAVER_H_
#define NODESAVER_H_

#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

//using namespace rapidjson;

namespace Golem {

class NodeSaver {
public:

    std::string name;
    std::string path;

    void load();
    void save();

    NodeSaver();
    virtual ~NodeSaver();
};

} /* namespace Golem */

#endif /* NODESAVER_H_ */
