//
// Created by lidor on 17/12/18.
//

#ifndef DEV_BINARYEXPRESSION_H
#define DEV_BINARYEXPRESSION_H

#include "Expression/Expression.h"

class BinaryExpression : public Expression {
protected:
    Expression *_rightExpression;
    Expression *_leftExpression;
public:
    BinaryExpression(Expression *right, Expression *left);

    const Expression *getRightExp();

    const Expression *getLeftExp();

    void setRightExp(Expression *e);

    void setLeftExp(Expression *e);

    virtual double calculate() = 0;

    virtual ~BinaryExpression();
};

#endif //DEV_BINARYEXPRESSION_H
