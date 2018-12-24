//
// Created by lidor115 on 12/20/18.
//

#ifndef UAV_PROJECT_DATA_H
#define UAV_PROJECT_DATA_H

#include <map>
#include "Var.h"

using namespace std;

class Data {
private:
    map<string, Var *> _symbolTable;
    map<string, double> _pathMap;
    multimap<string, Var *> _pathVarMap;
public:
    void addVar(string var_name, Var *var);

    void addPath(string path);

    void initPath();

    void addPathAndVar(Var *var, string path);

    Var *getVar(const string &var) const;

    bool isLeagalVar(const string &var) const;

    double getVarValue(const string &var) const;

    bool isPath(const string &var) const;

    void changeBindValue(string path, double val);

    bool isBind(const Var *var) const;

    void addBind(Var *var, const string &bind_adress);

    Data();

    void setPath(const string &path, double val);

    void assignVar(string var_name, double val);

    ~Data();

};

#endif //UAV_PROJECT_DATA_H
