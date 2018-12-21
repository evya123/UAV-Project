//
// Created by lidor115 on 12/20/18.
//

#include "Data.h"

void Data::addPath(string path, double val) {
    pathMap.insert(std::pair<string, double>(path, val));
}

void Data::addVar(string var, double val) {
    varMap.insert(std::pair<string, double>(var, val));
}

void Data::addPathAndVar(string var, string path) {
    mappingPathVar.insert(std::pair<string, string>(var, path));
}

map<string, string> Data::getMappingVarAndPath() const {
    return mappingPathVar;
}

map<string, double> Data::getPathMap() const {
    return pathMap;
}

map<string, double> Data::getVarMap() const {
    return varMap;
}