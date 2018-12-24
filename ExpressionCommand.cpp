//
// Created by lidor115 on 12/24/18.
//

#include "ExpressionCommand.h"

ExpressionCommand::ExpressionCommand(Command *command,
                                     vector<string> *arguments, Data *data) {
    _args = arguments;
    _data = data;
    _command = command;
}

double ExpressionCommand::calculate() {
    _command->doCommand(*_args, _data);
    return 0;
}