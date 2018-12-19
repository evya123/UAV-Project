//
// Created by lidor on 17/12/18.
//

#include "Mult.h"

double Mult::calculate() {
    return (_rightExpression->calculate() * _leftExpression->calculate());
}