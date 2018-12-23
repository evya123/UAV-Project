//
// Created by evya on 12/21/18.
//

#ifndef UAV_PROJECT_WHILECOMMAND_H
#define UAV_PROJECT_WHILECOMMAND_H
#include "Command.h"

class WhileCommand : public Command{
public:
    virtual void doCommand(const vector<string> &arguments, Data &d);
};


#endif //UAV_PROJECT_WHILECOMMAND_H
