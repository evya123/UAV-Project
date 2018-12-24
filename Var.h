//
// Created by lidor115 on 12/23/18.
//

#ifndef UAV_PROJECT_VAR_H
#define UAV_PROJECT_VAR_H

#include <string>
#include "Expression/Expression.h"

using namespace std;

class Var : public Expression {
private:
    string _name;
    string _bind_Adreess;
    double _val;
public:

    Var(string name);

    void assign(double val); /// to check if there is a bind

    void assign_from_bind(double val);

    void setBind(string bind);

    bool isBind() const;

    string getBindAdress() const;

    double getValue() const;

    double calculate();

    string getVarName() const;

};


#endif //UAV_PROJECT_VAR_H
