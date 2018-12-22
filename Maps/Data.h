//
// Created by lidor115 on 12/20/18.
//

#include <map>
#include "Commends/Command.h"

using namespace std;
#ifndef UAV_PROJECT_DATA_H
#define UAV_PROJECT_DATA_H

class Data {
    map<string, double> _symbolTable;
    map<string, double> _pathMap;
    map<string, string> _mappingPathVar;
public:
    void addVar(string var, double val);

    void initPath();

    void addPathAndVar(string var, string path);

    string getVar(const string var) const;

    string getPath(const string var) const;

    bool isLeagalVar(const string var) const;

    double getVarValue(const string var) const;

    void assignVar(const string var, double val);

    bool isPath(const string var) const;

    void changeBindValue(const string path, const double val);

    bool isBind(const string var) const;

    Data();

    ~Data();

};

#endif //UAV_PROJECT_DATA_H
