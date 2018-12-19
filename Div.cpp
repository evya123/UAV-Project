//
// Created by lidor on 17/12/18.
//

#include "Div.h"
double Div::calculate() {
    return (_rightExpression->calculate() / _leftExpression->calculate());
}