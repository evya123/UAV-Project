//נכ
// Created by lidor115 on 12/18/18.
//
#include <string>
#include "Expression.h"
using namespace std;
#ifndef DEV_SHUNTINGYARD_H
#define DEV_SHUNTINGYARD_H

class ShuntingYard {
    string tokens;
public:
    ShuntingYard(const string &tokens);
    double applyOp(double a, double b, char op);
    double precedence(char op);
    double evaluate();
};

#endif //DEV_SHUNTINGYARD_H
