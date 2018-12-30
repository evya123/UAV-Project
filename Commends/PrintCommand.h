//
// Created by evya on 12/21/18.
//

#ifndef UAV_PROJECT_PRINTCOMMAND_H
#define UAV_PROJECT_PRINTCOMMAND_H
#include "Command.h"
#include "Utils.h"

class PrintCommand : public Command{
public:
    PrintCommand()= default;
    virtual void doCommand(vector<string> &arguments, Data *d);
    void printMath(string &str, Data *d);
    ~PrintCommand(){}
};


#endif //UAV_PROJECT_PRINTCOMMAND_H
