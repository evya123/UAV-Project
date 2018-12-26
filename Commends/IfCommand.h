//
// Created by evya on 12/21/18.
//

#ifndef UAV_PROJECT_IFCOMMAND_H
#define UAV_PROJECT_IFCOMMAND_H

#include <Maps/MapStringCommand.h>
#include "Command.h"
#include "Commends/ConditionCommand.h"
#include "ArithmeticConditions.h"
#include "Control/LexerParser.h"

#define LHS 0
#define COMPARE 1
#define RHS 2

class IfCommand : public ConditionCommmand {
public:
    IfCommand();

    virtual void doCommand(vector<string> &arguments, Data *d);

private:
    vector<string>
    splitByDelimiter(vector<string>::iterator &, const string delimiter);

    ArithmeticConditions m_ac;
    MapStringCommand *m_msc;
};


#endif //UAV_PROJECT_IFCOMMAND_H
