//
// Created by evya on 12/21/18.
//


#ifndef UAV_PROJECT_VARCOMMAND_H
#define UAV_PROJECT_VARCOMMAND_H
#include "Command.h"
#include "Utils.h"
class VarCommand : public Command {
public:
    virtual void doCommand(vector<string> &arguments, Data *d);
    void RemoveQuotationMark(string &path);
    ~VarCommand();

};


#endif //UAV_PROJECT_VARCOMMAND_H
