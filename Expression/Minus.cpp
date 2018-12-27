//
// Created by lidor on 17/12/18.
//

#include "Minus.h"

/**
 * Minus class
 * @return the expression after the Minus
 */
double Minus::calculate() {
    return (_rightExpression->calculate() - _leftExpression->calculate());
}