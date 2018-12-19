//
// Created by lidor on 17/12/18.
//
#include "BinaryExpression.h"

#ifndef DEV_MULT_H
#define DEV_MULT_H
class Mult : public BinaryExpression {
public:
    Mult(Expression *right, Expression *left) : BinaryExpression(right, left){};

    double calculate();
};

#endif //DEV_MULT_H
