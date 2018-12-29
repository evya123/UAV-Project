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
            "/instrumentation/airspeed-indicator/indicated-speed-kt",
            0));
    this->_pathMap.insert(pair<string, double>(
            "/instrumentation/altimeter/indicated-altitude-ft", 0));
    this->_pathMap.insert(
            pair<string, double>
                    ("/instrumentation/altimeter/pressure-alt-ft",
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
            pair<string, double>
                    ("/instrumentation/gps/indicated-altitude-ft",
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
    this->_pathMap.insert(pair<string, double>("/controls/flight/aileron",
                                               0));
    this->_pathMap.insert(pair<string, double>
                                  ("/controls/flight/elevator", 0));
    this->_pathMap.insert(pair<string, double>("/controls/flight/rudder",
                                               0));
    this->_pathMap.insert(pair<string, double>("/controls/flight/flaps",
                                               0));
    this->_pathMap.insert(
            pair<string, double>("/controls/engines/current-engine/throttle",
                                 0));
    this->_pathMap.insert(pair<string, double>("/engines/engine/rpm", 0));
}

void Data::addVar(string var_name, Var *var) {
    unique_lock<mutex> lock(m_locker);//locked!
    _symbolTable.insert(std::pair<string, Var *>(var_name, var));
    checkMap.insert(std::pair<string, double>(var_name, var->calculate()));
    //unlocked!
    m_locker.unlock();
}

void Data::addPathAndVar(Var *var, string path) {
    unique_lock<mutex> lock(m_locker);//locked!
    _pathVarMap.insert(std::pair<string, Var *>(path, var));
    checkPathVar.insert(std::pair<string, string>(path, var->getVarName()));
    var->setBind(path);
    _pathMap[path] = var->getValue();
    m_locker.unlock();
    //unlocked!
}

bool Data::isLeagalVar(const string &var) {
    int res = _symbolTable.count(var);
    return (_symbolTable.count(var) > 0);
    //unlocked!
}

double Data::getVarValue(const string &var) {
    return checkMap.at(var);
    //unlocked!
}

bool Data::isBind(const Var *var) {
    return var->isBind();
    //unlocked!
}

bool Data::isPath(const string &var) {
    return (_pathMap.count(var) > 0);
}


void Data::changeBindValue(const string path, const double val) {
    unique_lock<mutex> lock(m_locker);//locked!
    _pathMap[path] = val;
    m_locker.unlock();
    //unlocked!
}

void Data::setPath(const string &path, double val) {
    if (isPath(path)) {
        unique_lock<mutex> lock(m_locker);//locked!
        _pathMap[path] = val;
        sendToClient(path, val); // send to the client
    }
    m_locker.unlock();
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
    checkMap[var_name] = val;
    v->assign(val);
    string path = v->getBindAdress();
    ///////////////////////////////////////////////////////////
    checkMap.insert(std::pair<string, double>(var_name, val));
    if (_pathMap.count(path) > 0) {
        _pathMap[path] = val;
//        RemoveQuotationMark(path);
        sendToClient(path, val);
    }
    m_locker.unlock();
    //unlocked!
}

void Data::addBind(Var *var, const string &bind_adress) {
    unique_lock<mutex> lock(m_locker);//locked!
    _pathVarMap.insert(pair<string, Var *>(bind_adress, var));
    m_locker.unlock();
    //unlocked!
}

void Data::changeVarBind(Var *var, string &bind) {
    unique_lock<mutex> lock(m_locker);//locked!
    var->setBind(bind);
    m_locker.unlock();
}

void Data::changeVarValue(Var *var, double value) {
    var->assign(value);
}

void Data::sendToClient(const string &path, double value) {
    string newPath = path;
    newPath.erase(newPath.begin());
    string s = "";
    s.clear();
    s += "set " + newPath + ' ' + to_string(value) + " \r\n";
    _client->Send(s);
}

/**
 *put arguments in the path map
 * @param toMap arguments of <path, value> to put in the path-map
 */
void Data::addToMapsFromServer(pair<string, double> &toMap) {
    string path = toMap.first;
    double val = toMap.second;
    string var_name = checkPathVar[path];
    unique_lock<mutex> lock(m_locker);//locked!
    // iterator of the multimap
    typedef std::multimap<string, Var *>::iterator MMAPIterator;
    cout << "var is : " << var_name << " path is : " << path <<
    " value is : """ << val << " "<<endl;
    _pathMap[path] = val;
    checkMap[var_name] = val;
    m_locker.unlock();

    /**
// change values of the vars bind with the changed values
std::pair<MMAPIterator, MMAPIterator> result = _pathVarMap
    .equal_range(path);
for (auto it = result.first; it !=result.second; ++it) {
it->second->assign(val);
}
     **/
}
