//
// Created by lidor on 17/12/18.
//
#include "BinaryExpression.h"

#ifndef DEV_DIV_H
#define DEV_DIV_H
class Div : public BinaryExpression {
public:
    Div(Expression *right, Expression *left) : BinaryExpression(right, left){};
    double calculate();

};

#endif //DEV_DIV_H
