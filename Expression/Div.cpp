//
// Created by lidor on 17/12/18.
//

#include "Div.h"
/**
 * Div class
 * @return the expression after the division
 */
double Div::calculate() {
    return (_rightExpression->calculate() / _leftExpression->calculate());
}