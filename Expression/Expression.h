#ifndef DEV_EXPRESSION_H
#define DEV_EXPRESSION_H

class Expression {
public:
    virtual double calculate() = 0;
    virtual ~Expression(){};
};

#endif //DEV_EXPRESSION_H
