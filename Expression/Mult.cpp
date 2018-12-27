//
// Created by lidor on 17/12/18.
//

#include "Mult.h"
/**
 * Mult class
 * @return the expression after the multiplication
 */
double Mult::calculate() {
    return (_rightExpression->calculate() * _leftExpression->calculate());
}