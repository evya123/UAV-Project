//
// Created by lidor on 17/12/18.
//

#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(Expression *right, Expression *left) {
    _rightExpression = right;
    _leftExpression = left;
}

const Expression *
BinaryExpression::getLeftExp() { return _leftExpression; }

const Expression *
BinaryExpression::getRightExp() { return _rightExpression; }

void BinaryExpression::setLeftExp(Expression *e) { _leftExpression = e; }

void BinaryExpression::setRightExp(Expression *e) { _rightExpression = e; }

BinaryExpression::~BinaryExpression() {
    delete (_leftExpression);
    delete (_rightExpression);
}