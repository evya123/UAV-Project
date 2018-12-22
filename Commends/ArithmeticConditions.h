//
// Created by evya on 12/22/18.
//

#ifndef UAV_PROJECT_ARITHMETICCONDITIONS_H
#define UAV_PROJECT_ARITHMETICCONDITIONS_H

#include <string>
#include <map>
typedef bool(*condition)(int,int);

using namespace std;

class ArithmeticConditions {
private:
    static bool equal(int lhs, int rhs) { return lhs == rhs;}
    static bool greater(int lhs, int rhs) { return lhs > rhs;}
    static bool smaller(int lhs, int rhs) { return lhs < rhs;}
    static bool equalOrGreater(int lhs, int rhs) { return lhs >= rhs;}
    static bool equalOrSmaller(int lhs, int rhs) { return lhs <= rhs;}
    static bool notEqual(int lhs, int rhs) { return lhs != rhs;}

    map<string, condition> m_conditionMap;

public:
    ArithmeticConditions();
    condition getCondition(const string &cond);
};


#endif //UAV_PROJECT_ARITHMETICCONDITIONS_H
