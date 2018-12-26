//
// Created by evya on 12/21/18.
//
#include "IfCommand.h"

void IfCommand::doCommand(vector<string> &arguments, Data *d) {
    auto it = arguments.begin();

    vector<string> ifArgs {arguments.at(LHS),arguments.at(RHS)};
    double lhsD, rhsD;
    lhsD = fromStringToNum(ifArgs[LHS],DOUBLE);
    rhsD = fromStringToNum(ifArgs[LHS],DOUBLE);
    if (m_ac.getCondition(arguments[COMPARE])(lhsD,rhsD));
        printf("success");
}

vector<string> IfCommand::splitByDelimiter(vector<string>::iterator &it,
                                           const string delimiter) {
    vector<string> ret;
    while ((*it).compare(delimiter) != 0) {
        ret.push_back((*it));
        ++it;
    }
    ++it;
    return ret;
}

bool IfCommand::checkCondition(vector<string> &arguments) {
    // now we
    // get 4 args - like x > 3 {
    //first argument
    string first_expression = arguments[1];
    // the condition
    string condition = arguments[2];
    // second argument
    string second_expression = arguments[3];
    // now we nee to have in args only {
    if (arguments[4] != "{") {
        throw "invalid Condition!";
    } else {
        //_numOfBrackets += 1;
    }
    ArithmeticConditions *arithmeticConditions = new ArithmeticConditions();
    double first = calculateExpression(first_expression, _data);
    double second = calculateExpression(second_expression, _data);
    // return if the condition is true or false
    return arithmeticConditions->getCondition(condition)(first, second);

}

void IfCommand::setMap(map<string, Command *>* map) {
    m_mapStringCommand = map;
}