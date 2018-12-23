//
// Created by evya on 12/21/18.
//

#ifndef UAV_PROJECT_VARCOMMAND_H
#define UAV_PROJECT_VARCOMMAND_H
#include "Command.h"

class VarCommand : public Command{
public:
    virtual void doCommand(const vector<string> &arguments, Date &d);

};


#endif //UAV_PROJECT_VARCOMMAND_H
