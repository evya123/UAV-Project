//
// Created by lidor on 17/12/18.
//

#ifndef DEV_MINUS_H
#define DEV_MINUS_H

#include "BinaryExpression.h"

class Minus : public BinaryExpression {
public:
    Minus(Expression *right, Expression *left): BinaryExpression(right,left){};
    double calculate();

};

#endif //DEV_MINUS_H
