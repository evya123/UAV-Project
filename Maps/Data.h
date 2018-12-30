//
// Created by lidor115 on 12/20/18.
//

#ifndef UAV_PROJECT_DATA_H
#define UAV_PROJECT_DATA_H

#include <map>
#include "Var.h"
#include <mutex>
#include <Commends/PullAndPush/TcpClient.h>
#include "Commends/PullAndPush/XmlFormat.h"

#define DELIMITER ","

using namespace std;

class Data {
private:
    map<string, Var *> _symbolTable;
    map<string, double> _pathMap;
    map<string, Var *> bindMap;
    mutex m_locker;
    TcpClient *_client;
public:
    Data(TcpClient *client);

    void addVar(string var_name, Var *var);

    void initPath();

    void addPathAndVar(Var *var, string path);

    Var *getVar(const string &var);

    bool isLeagalVar(const string &var);

    double getVarValue(const string &var);

    bool isPath(const string &var);

    void addBind(Var *var, const string &bind_adress);

    void setPath(const string &path, double val);

    void assignVar(string var_name, double val);

    void changeVarBind(Var *var, string &bind);

    void changeVarValue(Var *var, double value);

    void sendToClient(const string &path, double value);

    map<string, Var*> getBindMap();

    void addToMapsFromServer(pair<string, double> &toMap);

    void toMap(string toSplit);

    void sendToClientAllTheTime();

    ~Data();


};

#endif //UAV_PROJECT_DATA_H
