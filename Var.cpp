//
// Created by lidor115 on 12/23/18.
//

#include "Var.h"

/**
 * constructor
 * @param name of the variable
 * @param data (maps, etc)
 */
Var::Var(string name) {
    _name = name;
    _bind_Adreess = "";
    _val = 0;
}

/**
 * assign the val to the bind variable
 * @param val - set the bind variable updated
 */
void Var::assign(double val) {
    _val = val;
}

/**
 * set the var from the bind adrees
 * @param val we want to change
 */
void Var::assign_from_bind(double val) {
    _val = val;
}

void Var::setBind(string bind) {
    _bind_Adreess = bind;
}

double Var::getValue() const {
    return _val;
}

bool Var::isBind() const {
    return (!_bind_Adreess.empty());
}

string Var::getBindAdress() const {
    return _bind_Adreess;
}

double Var::calculate() {
    return _val;
}

string Var::getVarName() const {
    return _name;
}