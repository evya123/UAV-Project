//
// Created by evya on 12/21/18.
//

#ifndef UAV_PROJECT_IFCOMMAND_H
#define UAV_PROJECT_IFCOMMAND_H
#include "Command.h"

class IfCommand : public Command{
public:
    virtual void doCommand(const string &arguments);
};


#endif //UAV_PROJECT_IFCOMMAND_H
