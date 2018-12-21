//
// Created by lidor115 on 12/20/18.
//

#include <map>
#include "Commends/Command.h"

using namespace std;
#ifndef UAV_PROJECT_DATA_H
#define UAV_PROJECT_DATA_H

class Data {
    map<string, double> varMap;
    map<string, double> pathMap;
    map<string, string> mappingPathVar;
public:
    void addVar(string var, double val);

    void addPath(string path, double val);

    void addPathAndVar(string var, string path);

    void setVar(double val);

    map<string, double> getVarMap() const;

    map<string, double> getPathMap() const;

    map<string, string> getMappingVarAndPath() const;

    map<string, Command *> mapStringToCommand;


};

#endif //UAV_PROJECT_DATA_H
