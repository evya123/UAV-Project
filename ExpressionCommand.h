//
// Created by lidor115 on 12/24/18.
//

#ifndef UAV_PROJECT_EXPRESSIONCOMMAND_H
#define UAV_PROJECT_EXPRESSIONCOMMAND_H

#include "Commends/Command.h"

#endif //UAV_PROJECT_EXPRESSIONCOMMAND_H

class ExpressionCommand : public Expression {
private:
    Command *_command;
    vector<string> *_args;
    Data *_data;
public:
    ExpressionCommand(Command* command, vector<string> *arguments, Data *data);

    double calculate();
};