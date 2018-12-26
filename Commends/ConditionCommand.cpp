//
// Created by lidor115 on 12/26/18.
//

#include "ConditionCommand.h"

ConditionCommmand::ConditionCommmand(Data *data,
                                     MapStringCommand *mapStringCommand) {
    _data = data;
    _mapStringCommand = mapStringCommand;
    _numOfBrackets = 0;
}

void ConditionCommmand::CommandParser(vector<string> &commands,
                                      vector<string> &arguments) {

}

/**
 * check the condition and return true or false
 * @param arguments
 */
bool ConditionCommmand::checkCondition(vector<string> &arguments) {    // now we
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
        ++_numOfBrackets;
    }
    ArithmeticConditions *arithmeticConditions = new ArithmeticConditions();
    double first = calculateExpression(first_expression, _data);
    double second = calculateExpression(second_expression, _data);
    // return if the condition is true or false
    return arithmeticConditions->getCondition(condition)(first, second);

}//Todo
