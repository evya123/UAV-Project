//
// Created by evya on 12/21/18.
//

#ifndef UAV_PROJECT_CONNECTCOMMAND_H
#define UAV_PROJECT_CONNECTCOMMAND_H

#include "Command.h"
#include <iostream>

class ConnectCommand : public Command{

public:
    ConnectCommand() = default;
    virtual void doCommand(const vector<string> arguments);
};


#endif //UAV_PROJECT_CONNECTCOMMAND_H
