//
// Created by evya on 12/21/18.
//

#ifndef UAV_PROJECT_IFCOMMAND_H
#define UAV_PROJECT_IFCOMMAND_H

#include "Commends/Command.h"
#include "ArithmeticConditions.h"
#include "Utils.h"

#define LHS 0
#define COMPARE 1
#define RHS 2

class IfCommand : public Command {
public:
    IfCommand() = default;
    virtual void doCommand(vector<string> &arguments, Data *d);
    void setMap(map<string, Command *>*);

private:
    bool checkCondition(vector<string> &arguments, Data *_data);
    map<string, Command *>* m_mapStringCommand;
    vector<string>
    splitByDelimiter(vector<string>::iterator &, const string delimiter);

    ArithmeticConditions m_ac;
};


#endif //UAV_PROJECT_IFCOMMAND_H