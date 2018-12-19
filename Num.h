//
// Created by lidor115 on 12/18/18.
//

#ifndef DEV_NUM_H
#define DEV_NUM_H

#include "Expression.h"

class Num: public Expression{
    double _num;

public:
    Num(double n);
    double calculate();
};
#endif //DEV_NUM_H
