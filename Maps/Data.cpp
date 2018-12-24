//
// Created by lidor115 on 12/20/18.
//

#include "Data.h"

Data::Data() {
    initPath();
}

void Data::initPath() {
    this->_pathMap.insert(pair<string, double>(
            "\"/instrumentation/airspeed-indicator/indicated-speed-kt\"",
            0));
    this->_pathMap.insert(pair<string, double>(
            "\"/instrumentation/altimeter/indicated-altitude-ft\"", 0));
    this->_pathMap.insert(
            pair<string, double>
                    ("\"instrumentation/altimeter/pressure-alt-ft\"",
                                 0));
    this->_pathMap.insert(pair<string, double>(
            "\"/instrumentation/attitude-indicator/indicated-pitch-deg\"", 0));
    this->_pathMap.insert(pair<string, double>(
            "\"/instrumentation/attitude-indicator/indicated-roll-deg\"", 0));
    this->_pathMap.insert(pair<string, double>(
            "\"/instrumentation/attitude-indicator/internal-pitch-deg\"", 0));
    this->_pathMap.insert(pair<string, double>(
            "\"/instrumentation/attitude-indicator/internal-roll-deg\"", 0));
    this->_pathMap.insert(pair<string, double>(
            "\"/instrumentation/encoder/indicated-altitude-ft\"", 0));
    this->_pathMap.insert(
            pair<string, double>("\"/instrumentation/encoder/pressure-alt-ft\"",
                                 0));
    this->_pathMap.insert(
            pair<string, double>
                    ("\"/instrumentation/gps/indicated-altitude-ft\"",
                                 0));
    this->_pathMap.insert(pair<string, double>(
            "\"/instrumentation/gps/indicated-ground-speed-kt", 0));
    this->_pathMap.insert(pair<string, double>(
            "\"/instrumentation/gps/indicated-vertical-speed", 0));
    this->_pathMap.insert(pair<string, double>(
            "\"/instrumentation/heading-indicator/indicated-heading-deg\"", 0));
    this->_pathMap.insert(pair<string, double>
                                  ("\"/instrumentation/magnetic-compass/indicated-heading-deg\"",
                                   0));
    this->_pathMap.insert(pair<string, double>(
            "\"/instrumentation/slip-skid-ball/indicated-slip-skid\"", 0));
    this->_pathMap.insert(pair<string, double>(
            "\"/instrumentation/turn-indicator/indicated-turn-rate\"", 0));
    this->_pathMap.insert(pair<string, double>(
            "\"/instrumentation/vertical-speed-indicator/indicated-speed-fpm\"",
            0));
    this->_pathMap.insert(pair<string, double>("\"/controls/flight/aileron\"",
    0));
    this->_pathMap.insert(pair<string, double>
            ("\"/controls/flight/elevator\"", 0));
    this->_pathMap.insert(pair<string, double>("\"/controls/flight/rudder\"",
    0));
    this->_pathMap.insert(pair<string, double>("\"/controls/flight/flaps\"",
            0));
    this->_pathMap.insert(
            pair<string, double>("\"/controls/engines/engine/throttle\"", 0));
    this->_pathMap.insert(pair<string, double>("\"/engines/engine/rpm\"", 0));
    this->_pathMap.insert(pair<string, double>
            ("\"/controls/engines/current-engine/throttle\"", 0));

}

void Data::addVar(string var_name, Var *var) {
    _symbolTable.insert(std::pair<string, Var *>(var_name, var));
}

void Data::addPathAndVar(Var *var, string path) {
    _pathVarMap.insert(std::pair<string, Var *>(path, var));
    var->setBind(path);
    _pathMap[path] = var->getValue();
}

bool Data::isLeagalVar(const string &var) const {
    return (_symbolTable.count(var) > 0);
}

double Data::getVarValue(const string &var) const {
    return _symbolTable.at(var)->getValue();
}

bool Data::isBind(const Var *var) const {
    return var->isBind();
}

bool Data::isPath(const string &var) const {
    return (_pathMap.count(var) > 0);
}


void Data::changeBindValue(const string path, const double val) {
    _pathMap[path] = val;
}

void Data::setPath(const string &path, double val) {
    if (isPath(path)) {
        _pathMap[path] = val;
    }
}

Var *Data::getVar(const string &var) const {
    if (isLeagalVar(var)) {
        return _symbolTable.at(var);
    }
}

void Data::assignVar(string var_name, double val) {
    Var *v = _symbolTable[var_name];
    v->assign(val);
    if (isBind(v)) {
        _pathMap[v->getBindAdress()] = val;
    }
}

void Data::addBind(Var *var, const string &bind_adress) {
    _pathVarMap.insert(pair<string, Var *>(bind_adress, var));
}

