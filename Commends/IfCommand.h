//
// Created by evya on 12/21/18.
//

#ifndef UAV_PROJECT_IFCOMMAND_H
#define UAV_PROJECT_IFCOMMAND_H

#include "Command.h"
#include "../Control/LexerParser.h"

class LexerParser;
class IfCommand : public Command {
public:
    IfCommand(LexerParser *);
    virtual void doCommand(vector<string> &arguments, Data *d);
private:
    queue<vector<string>> m_conditions;
    queue<vector<string>> m_commands;
    LexerParser* m_lp;
    ~IfCommand(){}
};


#endif //UAV_PROJECT_IFCOMMAND_H