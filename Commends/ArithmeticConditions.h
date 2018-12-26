//
// Created by evya on 12/22/18.
//

#ifndef UAV_PROJECT_ARITHMETICCONDITIONS_H
#define UAV_PROJECT_ARITHMETICCONDITIONS_H

#include <string>
#include <map>
typedef bool(*condition)(double,double);

using namespace std;

class ArithmeticConditions {
private:
    static bool equal(double lhs, double rhs) { return lhs == rhs;}
    static bool greater(double lhs, double rhs) { return lhs > rhs;}
    static bool smaller(double lhs, double rhs) { return lhs < rhs;}
    static bool equalOrGreater(double lhs, double rhs) { return lhs >= rhs;}
    static bool equalOrSmaller(double lhs, double rhs) { return lhs <= rhs;}
    static bool notEqual(double lhs, double rhs) { return lhs != rhs;}

    map<string, condition> m_conditionMap;

public:
    ArithmeticConditions();
    condition getCondition(const string &cond);
};


#endif //UAV_PROJECT_ARITHMETICCONDITIONS_H
