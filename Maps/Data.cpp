//
// Created by lidor115 on 12/20/18.
//

#include "Data.h"

Data::Data() {
    initPath();
}

void Data::initPath() {
    this->_pathMap.insert(pair<string, double>(
            "/instrumentation/airspeed-indicator/indicated-speed-kt", 0));
    this->_pathMap.insert(pair<string, double>(
            "/instrumentation/altimeter/indicated-altitude-ft", 0));
    this->_pathMap.insert(
            pair<string, double>("/instrumentation/altimeter/pressure-alt-ft",
                                 0));
    this->_pathMap.insert(pair<string, double>(
            "/instrumentation/attitude-indicator/indicated-pitch-deg", 0));
    this->_pathMap.insert(pair<string, double>(
            "/instrumentation/attitude-indicator/indicated-roll-deg", 0));
    this->_pathMap.insert(pair<string, double>(
            "/instrumentation/attitude-indicator/internal-pitch-deg", 0));
    this->_pathMap.insert(pair<string, double>(
            "/instrumentation/attitude-indicator/internal-roll-deg", 0));
    this->_pathMap.insert(pair<string, double>(
            "/instrumentation/encoder/indicated-altitude-ft", 0));
    this->_pathMap.insert(
            pair<string, double>("/instrumentation/encoder/pressure-alt-ft",
                                 0));
    this->_pathMap.insert(
            pair<string, double>("/instrumentation/gps/indicated-altitude-ft",
                                 0));
    this->_pathMap.insert(pair<string, double>(
            "/instrumentation/gps/indicated-ground-speed-kt", 0));
    this->_pathMap.insert(pair<string, double>(
            "/instrumentation/gps/indicated-vertical-speed", 0));
    this->_pathMap.insert(pair<string, double>(
            "/instrumentation/heading-indicator/indicated-heading-deg", 0));
    this->_pathMap.insert(pair<string, double>
                                  ("/instrumentation/magnetic-compass/indicated-heading-deg",
                                   0));
    this->_pathMap.insert(pair<string, double>(
            "/instrumentation/slip-skid-ball/indicated-slip-skid", 0));
    this->_pathMap.insert(pair<string, double>(
            "/instrumentation/turn-indicator/indicated-turn-rate", 0));
    this->_pathMap.insert(pair<string, double>(
            "/instrumentation/vertical-speed-indicator/indicated-speed-fpm",
            0));
    this->_pathMap.insert(pair<string, double>("/controls/flight/aileron", 0));
    this->_pathMap.insert(pair<string, double>("/controls/flight/elevator", 0));
    this->_pathMap.insert(pair<string, double>("/controls/flight/rudder", 0));
    this->_pathMap.insert(pair<string, double>("/controls/flight/flaps", 0));
    this->_pathMap.insert(
            pair<string, double>("/controls/engines/engine/throttle", 0));
    this->_pathMap.insert(pair<string, double>("/engines/engine/rpm", 0));

}

void Data::addVar(string var, double val) {
    _symbolTable.insert(std::pair<string, double>(var, val));
}

void Data::addPathAndVar(string var, string path) {
    _mappingPathVar.insert(std::pair<string, string>(var, path));
}

bool Data::isLeagalVar(const string var) const {
    if (_symbolTable.count(var) > 0) {
        return true;
    }
    return false;
}

double Data::getVarValue(const string var) const {
    return _symbolTable.at(var);
}

string Data::getPath(const string var) const {
    return _mappingPathVar.at(var);
}

void Data::assignVar(const string var, double val) {
    // if the var is already exist - change the var and the bind table
    if (isLeagalVar(var)) {
        _symbolTable.at(var) = val;
        if (isBind(var)) {
            string bind = _mappingPathVar[var];
            _pathMap.at(bind) = val;
        }
        // its a new var - add to the symbolTable
    } else {
        _symbolTable.insert(pair<string, double>(var, val));
    }
}

bool Data::isBind(const string var) const {
    if (_mappingPathVar.count(var) > 0) {
        return true;
    }
    return false;
}

bool Data::isPath(const string var) const {
    if (_pathMap.count(var) > 0) {
        return true;
    }
    return false;
}

void Data::changeBindValue(const string path, const double val) {
    _pathMap[path] = val;
}