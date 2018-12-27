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
    vector<string> conditionVec = m_allCommands.front();
    if (Utils::checkCondition(conditionVec,d,m_brackets)) {
        //TODO: from here till the end, I execute every command but ifs and whiles.
        //If I encounter if or while I create a vector that contains all the data
        //in the condition scope and move it to parser, which means until the next if or while
    }
    return;
}

