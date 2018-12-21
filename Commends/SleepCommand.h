//
// Created by evya on 12/21/18.
//

#ifndef UAV_PROJECT_SLEEPCOMMAND_H
#define UAV_PROJECT_SLEEPCOMMAND_H
#include "Command.h"
#include<unistd.h>

class SleepCommand : public Command{
public:
    virtual void doCommand(const string &arguments);

};


#endif //UAV_PROJECT_SLEEPCOMMAND_H
