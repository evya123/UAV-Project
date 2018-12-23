//
// Created by evya on 12/21/18.
//

#ifndef UAV_PROJECT_IFCOMMAND_H
#define UAV_PROJECT_IFCOMMAND_H

#include <Maps/MapStringCommand.h>
#include "Command.h"
#include "ArithmeticConditions.h"
#include "Control/LexerParser.h"

class IfCommand : public Command{
public:
    IfCommand(MapStringCommand* mpc);
    virtual void doCommand(vector<string> &arguments, Data *d);

private:
    LexerParser lp;
    ArithmeticConditions m_ac;
    MapStringCommand* m_msc;
};


#endif //UAV_PROJECT_IFCOMMAND_H
