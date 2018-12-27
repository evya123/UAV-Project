//
// Created by lidor on 17/12/18.
//

#include "Plus.h"
/**
 * Plus class
 * @return the expression after the Plus operation
 */
double Plus::calculate() {
    return (_rightExpression->calculate() + _leftExpression->calculate());
}