//
// Created by lidor on 17/12/18.
//
#include "BinaryExpression.h"
#ifndef DEV_PLUS_H
#define DEV_PLUS_H
class Plus : public BinaryExpression {
public:
    Plus(Expression *right, Expression *left) : BinaryExpression(right, left){};

    double calculate();
};
#endif //DEV_PLUS_H
