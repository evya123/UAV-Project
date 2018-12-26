//
// Created by evya on 12/21/18.
//

#ifndef UAV_PROJECT_IFCOMMAND_H
#define UAV_PROJECT_IFCOMMAND_H

#include "Command.h"
#include "ArithmeticConditions.h"

#define LHS 0
#define COMPARE 1
#define RHS 2
class IfCommand : public Command{
public:
    IfCommand();
    virtual void doCommand(vector<string> &arguments, Data *d);

private:
    vector<string> splitByDelimiter(vector<string>::iterator&,const string delimiter);
    ArithmeticConditions m_ac;
};


#endif //UAV_PROJECT_IFCOMMAND_H
