//
// Created by evya on 12/21/18.
//

#ifndef UAV_PROJECT_IFCOMMAND_H
#define UAV_PROJECT_IFCOMMAND_H

#include "Commends/Command.h"
#include "Utils.h"
#include "Maps/MapStringCommand.h"

class IfCommand : public Command {
public:
    IfCommand() = default;
    virtual void doCommand(vector<string> &arguments, Data *d);

private:
    stack<string> m_brackets;
};


#endif //UAV_PROJECT_IFCOMMAND_H