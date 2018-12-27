//
// Created by evya on 12/21/18.
//

#ifndef UAV_PROJECT_IFCOMMAND_H
#define UAV_PROJECT_IFCOMMAND_H

#include "Commends/Command.h"
#include "Control/LexerParser.h"
#define IF_CHECK "if"
class LexerParser;
class IfCommand : public Command {
public:
    IfCommand(LexerParser *);
    virtual void doCommand(vector<string> &arguments, Data *d);
private:
    queue<vector<string>> m_conditions;
    queue<vector<string>> m_commands;
    LexerParser* m_lp;
};


#endif //UAV_PROJECT_IFCOMMAND_H