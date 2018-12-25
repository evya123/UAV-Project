//
// Created by lidor115 on 12/20/18.
//

#include "Data.h"

Data::Data(TcpClient *client) {
    _client = client;
    initPath();
}

void Data::initPath() {
    this->_pathMap.insert(pair<string, double>(
            "instrumentation/airspeed-indicator/indicated-speed-kt",
            0));
    this->_pathMap.insert(pair<string, double>(
            "instrumentation/altimeter/indicated-altitude-ft", 0));
    this->_pathMap.insert(
            pair<string, double>
                    ("instrumentation/altimeter/pressure-alt-ft",
                     0));
    this->_pathMap.insert(pair<string, double>(
            "instrumentation/attitude-indicator/indicated-pitch-deg", 0));
    this->_pathMap.insert(pair<string, double>(
            "instrumentation/attitude-indicator/indicated-roll-deg", 0));
    this->_pathMap.insert(pair<string, double>(
            "instrumentation/attitude-indicator/internal-pitch-deg", 0));
    this->_pathMap.insert(pair<string, double>(
            "instrumentation/attitude-indicator/internal-roll-deg", 0));
    this->_pathMap.insert(pair<string, double>(
            "instrumentation/encoder/indicated-altitude-ft", 0));
    this->_pathMap.insert(
            pair<string, double>("instrumentation/encoder/pressure-alt-ft",
                                 0));
    this->_pathMap.insert(
            pair<string, double>
                    ("instrumentation/gps/indicated-altitude-ft",
                     0));
    this->_pathMap.insert(pair<string, double>(
            "instrumentation/gps/indicated-ground-speed-kt", 0));
    this->_pathMap.insert(pair<string, double>(
            "instrumentation/gps/indicated-vertical-speed", 0));
    this->_pathMap.insert(pair<string, double>(
            "instrumentation/heading-indicator/indicated-heading-deg", 0));
    this->_pathMap.insert(pair<string, double>
                                  ("instrumentation/magnetic-compass/indicated-heading-deg",
                                   0));
    this->_pathMap.insert(pair<string, double>(
            "instrumentation/slip-skid-ball/indicated-slip-skid", 0));
    this->_pathMap.insert(pair<string, double>(
            "instrumentation/turn-indicator/indicated-turn-rate", 0));
    this->_pathMap.insert(pair<string, double>(
            "instrumentation/vertical-speed-indicator/indicated-speed-fpm",
            0));
    this->_pathMap.insert(pair<string, double>("controls/flight/aileron",
                                               0));
    this->_pathMap.insert(pair<string, double>
                                  ("controls/flight/elevator", 0));
    this->_pathMap.insert(pair<string, double>("controls/flight/rudder",
                                               0));
    this->_pathMap.insert(pair<string, double>("controls/flight/flaps",
                                               0));
    this->_pathMap.insert(
            pair<string, double>("controls/engines/current-engine/throttle", 0));
    this->_pathMap.insert(pair<string, double>("engines/engine/rpm", 0));
}

void Data::addVar(string var_name, Var *var) {
    unique_lock<mutex> lock(m_locker);//locked!
    _symbolTable.insert(std::pair<string, Var *>(var_name, var));
    //unlocked!
}

void Data::addPathAndVar(Var *var, string path) {
    unique_lock<mutex> lock(m_locker);//locked!
    _pathVarMap.insert(std::pair<string, Var *>(path, var));
    var->setBind(path);
    _pathMap[path] = var->getValue();
    //unlocked!
}

bool Data::isLeagalVar(const string &var) {
    unique_lock<mutex> lock(m_locker);//locked!
    return (_symbolTable.count(var) > 0);
    //unlocked!
}

double Data::getVarValue(const string &var) {
    unique_lock<mutex> lock(m_locker);//locked!
    return _symbolTable.at(var)->getValue();
    //unlocked!
}

bool Data::isBind(const Var *var) {
    unique_lock<mutex> lock(m_locker);//locked!
    return var->isBind();
    //unlocked!
}

bool Data::isPath(const string &var) {
    unique_lock<mutex> lock(m_locker);//locked!
    return (_pathMap.count(var) > 0);
    //unlocked!
}


void Data::changeBindValue(const string path, const double val) {
    unique_lock<mutex> lock(m_locker);//locked!
    _pathMap[path] = val;
    //unlocked!
}

void Data::setPath(const string &path, double val) {
    if (isPath(path)) {
        unique_lock<mutex> lock(m_locker);//locked!
        _pathMap[path] = val;
        sendToClient(path, val); // send to the client
    }
    //unlocked!
}

Var *Data::getVar(const string &var) {
    if (isLeagalVar(var)) {
        unique_lock<mutex> lock(m_locker);//locked!
        return _symbolTable.at(var);
    }
    //unlocked!
}

void Data::assignVar(string var_name, double val) {
    unique_lock<mutex> lock(m_locker);//locked!
    Var *v = _symbolTable[var_name];
    v->assign(val);
    string path = v->getBindAdress();
    if (_pathMap.count(path) > 0) {
        _pathMap[path] = val;
//        RemoveQuotationMark(path);

        sendToClient(path, val);
    }
    //unlocked!
}

void Data::addBind(Var *var, const string &bind_adress) {
    unique_lock<mutex> lock(m_locker);//locked!
    _pathVarMap.insert(pair<string, Var *>(bind_adress, var));
    //unlocked!
}

void Data::changeVarBind(Var *var, string &bind) {
    unique_lock<mutex> lock(m_locker);//locked!
    var->setBind(bind);
}

void Data::changeVarValue(Var *var, double value) {
    unique_lock<mutex> lock(m_locker);//locked!
    var->assign(value);
}

void Data::sendToClient(const string &path, double value) {
    string s = "";
    s += "set " + path + " " + to_string(value);
    _client->Send(s);
}
/*
void Data::RemoveQuotationMark(string &path) {
    path.erase(remove(path.begin(), path.end(), ), path.end());
    path.erase(path.begin());
}
*/
void Data::addToMapsFromServer(pair<string, double> &toMap) {
    typedef std::multimap<string, Var *>::iterator MMAPIterator;
    unique_lock<mutex> lock(m_locker);//locked!
    string path = toMap.first;
    double val = toMap.second;
    _pathMap[path] = val;
    std::pair<MMAPIterator, MMAPIterator> result = _pathVarMap
            .equal_range(path);
    for (auto it = result.first; it !=result.second; ++it) {
        it->second->assign(val);
    }
}
