//
// Created by evya on 12/21/18.
//


#ifndef UAV_PROJECT_VARCOMMAND_H
#define UAV_PROJECT_VARCOMMAND_H
#include "Command.h"
#include "Maps/MapStringCommand.h"
#include "Expression/ShuntingYard.h"
#include "Utils.h"
#include "Var.h"

class VarCommand : public Command {

public:
    virtual void doCommand(vector<string> &arguments, Data *d);

};


#endif //UAV_PROJECT_VARCOMMAND_H
