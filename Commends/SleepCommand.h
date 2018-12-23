//
// Created by evya on 12/21/18.
//

#ifndef UAV_PROJECT_SLEEPCOMMAND_H
#define UAV_PROJECT_SLEEPCOMMAND_H
#include "Command.h"
#include<unistd.h>
#define SLEEP_TIME 0

class SleepCommand : public Command{
public:
    virtual void doCommand(vector<string> &arguments, Data &d);

};


#endif //UAV_PROJECT_SLEEPCOMMAND_H
