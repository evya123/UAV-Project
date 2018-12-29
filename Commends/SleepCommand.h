//
// Created by evya on 12/21/18.
//

#ifndef UAV_PROJECT_SLEEPCOMMAND_H
#define UAV_PROJECT_SLEEPCOMMAND_H

#include "Command.h"
#include "Utils.h"


class SleepCommand : public Command {
public:
    virtual void doCommand(vector<string> &arguments, Data *d);

};


#endif //UAV_PROJECT_SLEEPCOMMAND_H
