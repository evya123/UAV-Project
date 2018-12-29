//
// Created by lidor115 on 12/20/18.
//

#include <Utils.h>
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
            pair<string, double>("controls/engines/current-engine/throttle",
                                 0));
    this->_pathMap.insert(pair<string, double>("engines/engine/rpm", 0));
}

/**
 * add to symbole table name and 0
 * @param var_name  name
 * @param var  the var (allocated from VarCommand)
 */
void Data::addVar(string var_name, Var *var) { // just add name
    unique_lock<mutex> lock(m_locker);
    _symbolTable.insert(std::pair<string, Var *>(var_name, var));
    lock.unlock();
}

/**
 * add path and var (which is bind with)
 * @param var
 * @param path
 */
void Data::addPathAndVar(Var *var, string path) { // just name and path
    unique_lock<mutex> lock(m_locker);
    bindMap.insert(std::pair<string, Var *>(path, var));
    var->setBind(path);
    _pathMap[path] = var->getValue();
    lock.unlock();
}

/**
 * return if there is a var or not
 * @param var  var name
 * @return if there is a var or not
 */
bool Data::isLeagalVar(const string &var) {
    unique_lock<mutex> lock(m_locker);
    return (_symbolTable.count(var) > 0);
    lock.unlock();
}

/**
 *
 * @param var the var name
 * @return the value of the var if its leagal var
 */
double Data::getVarValue(const string &var) {
    unique_lock<mutex> lock(m_locker);
    if (_symbolTable.count(var) > 0) {
        return _symbolTable[var]->getValue();
    }
    lock.unlock();
}

bool Data::isPath(const string &var) {
    return (_pathMap.count(var) > 0);
}

/*
 * set the maps of bind and path maps
 */
void Data::setPath(const string &path, double val) {
    unique_lock<mutex> lock(m_locker);
    if (bindMap.count(path) > 0) {
        bindMap[path]->assign(val);
    }
    if (_pathMap.count(path) > 0) {
        _pathMap[path] = val;
    }
    lock.unlock();
}

/**
 * return the var if exist
 */
Var *Data::getVar(const string &var) {
    unique_lock<mutex> lock(m_locker);
    if (_symbolTable.count(var) > 0) {
        return _symbolTable.at(var);
    }
    lock.unlock();
    //unlocked!
}

void Data::assignVar(string var_name, double val) {
    unique_lock<mutex> lock(m_locker);
    Var *v = _symbolTable[var_name];
    v->assign(val);
    string path = v->getBindAdress();
    if (v->isBind()) { // only from the xml
        _pathMap[path] = val;
    }
    lock.unlock();
    if (bindMap.count(path) > 0) {
        sendToClient(path, val);
    }
}

void Data::addBind(Var *var, const string &bind_adress) {
    unique_lock<mutex> lock(m_locker);
    bindMap.insert(pair<string, Var *>(bind_adress, var));
    if (isPath(bind_adress)) {
        var->assign(_pathMap[bind_adress]);
    }
    bindMap[bind_adress] = var;
    lock.unlock();
}

map<string, Var *> Data::getBindMap() {
    return bindMap;
}

void Data::changeVarBind(Var *var, string &bind) {
    unique_lock<mutex> lock(m_locker);
    var->setBind(bind);
    lock.unlock();
}

void Data::changeVarValue(Var *var, double value) {
    unique_lock<mutex> lock(m_locker);
    var->assign(value);
    string path = var->getBindAdress();
    if (isPath(var->getVarName())) {
        _pathMap[path] = value;
    }
    lock.unlock();
    sendToClient(var->getBindAdress(), value);
}

void Data::sendToClient(const string &path, double value) {
    string s = "";
    s.clear();
    s += "set " + path + " " + to_string(value) + "\r\n";
    cout << s << endl;
    _client->Send(s);
}

/**
 *put arguments in the path map
 * @param toMap arguments of <path, value> to put in the path-map
 */
void Data::addToMapsFromServer(pair<string, double> &toMap) {
    string path = toMap.first;
    path.erase(path.begin());
    double val = toMap.second;
    unique_lock<mutex> lock(m_locker);
    if (isPath(path)) {
        _pathMap[path] = val;
    }
    string var_name = "";
    if (bindMap.count(path) > 0) {
        bindMap[path]->assign(val);
        var_name = bindMap[path]->getVarName();
    }
    lock.unlock();
}

void Data::toMap(string toSplit) {
    auto it = m_xmlHandler.begin();
    size_t pos = 0;
    while (!toSplit.empty()) {
        if (++it == m_xmlHandler.end())
            break;
        pos = toSplit.find(DELIMITER);
        string splitted = toSplit.substr(0, pos);
        pair<string, double> p = make_pair(*it, Utils::fromStringToNum
                (splitted, DOUBLE));
        addToMapsFromServer(p);
        toSplit.erase(0, pos + 1);
       // if (++it == m_xmlHandler.end())
          //  break;
    }
}