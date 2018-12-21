//
// Created by lidor on 17/12/18.
//

#include "Plus.h"

double Plus::calculate() {
    return (_rightExpression->calculate() + _leftExpression->calculate());
}