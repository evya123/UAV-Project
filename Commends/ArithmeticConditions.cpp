//
// Created by evya on 12/22/18.
//

#include "ArithmeticConditions.h"

ArithmeticConditions::ArithmeticConditions() {
    m_conditionMap.insert(make_pair("==",equal));
    m_conditionMap.insert(make_pair(">",greater));
    m_conditionMap.insert(make_pair("<",smaller));
    m_conditionMap.insert(make_pair(">=",equalOrGreater));
    m_conditionMap.insert(make_pair("=>",equalOrGreater));
    m_conditionMap.insert(make_pair("<=",equalOrSmaller));
    m_conditionMap.insert(make_pair("=<",equalOrSmaller));
    m_conditionMap.insert(make_pair("!=",notEqual));
    m_conditionMap.insert(make_pair("=!",notEqual));

}
condition ArithmeticConditions::getCondition(const string &cond) {
    return m_conditionMap.find(cond)->second;
}
