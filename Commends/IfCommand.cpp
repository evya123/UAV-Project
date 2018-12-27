//
// Created by evya on 12/21/18.
//

#include "IfCommand.h"

IfCommand::IfCommand(LexerParser *lp) {
    m_lp = lp;
}

void IfCommand::doCommand(vector<string> &arguments, Data *d) {
    auto it = arguments.begin();
    while(it != arguments.end()){
        auto tmpVec = Utils::splitByDelimiter(it,BRACKET);
        if(!tmpVec.empty())
            m_allCommands.push_back(tmpVec);
        if ((*it).compare(BRACKET) == 0){
            m_brackets.push(*it);
            ++it;
        } else if ((*it).compare(CLOSING_BRACKET) == 0){
            m_brackets.pop();
            ++it;
        }
    }
    auto firstCommand = m_allCommands.data();
    if(firstCommand->at(0).compare("if") == 0){

    }
    return;
}

