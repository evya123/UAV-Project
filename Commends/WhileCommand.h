//
// Created by evya on 12/21/18.
//

#ifndef UAV_PROJECT_WHILECOMMAND_H
#define UAV_PROJECT_WHILECOMMAND_H
#include "Command.h"
#include "Utils.h"

class WhileCommand : public Command{
public:
    virtual void doCommand(vector<string> &arguments, Data *d);

private:
    stack<string> m_brackets;

};


#endif //UAV_PROJECT_WHILECOMMAND_H
