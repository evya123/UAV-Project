//
// Created by evya on 12/21/18.
//

#ifndef UAV_PROJECT_PRINTCOMMAND_H
#define UAV_PROJECT_PRINTCOMMAND_H
#include "Command.h"
#include <iostream>

class PrintCommand : public Command{
public:
    PrintCommand()= default;
    virtual void doCommand(vector<string> &arguments, Data *d);

};


#endif //UAV_PROJECT_PRINTCOMMAND_H
