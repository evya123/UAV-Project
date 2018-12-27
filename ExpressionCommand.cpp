//
// Created by lidor115 on 12/24/18.
//

#include "ExpressionCommand.h"
/**
 * constructor of expression command
 * @param command
 * @param arguments arguments of the expression (expression-command)
 * @param data the data
 */
ExpressionCommand::ExpressionCommand(Command *command,
                                     vector<string> *arguments, Data *data) {
    _args = arguments;
    _data = data;
    _command = command;
}
/**
 * do command of the expression
 * @return zero (nothing)
 */
double ExpressionCommand::calculate() {
    _command->doCommand(*_args, _data);
    return 0;
}