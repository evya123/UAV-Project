//
// Created by lidor on 17/12/18.
//

#include "Minus.h"
double Minus::calculate() {
    return (_rightExpression->calculate() - _leftExpression->calculate());
}