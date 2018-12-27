//
// Created by evya on 12/21/18.
//

#include "IfCommand.h"

IfCommand::IfCommand(LexerParser *lp) {
    m_lp = lp;
}

void IfCommand::doCommand(vector<string> &arguments, Data *d) {
    auto it = arguments.begin();
    vector<string> commandsTmp;
    while (it != arguments.end()) {
        if ((*it).compare(IF_CHECK) == 0) {
            vector<string> conditionTmp;
            while((*it).compare(BRACKET)){
                if ((*it).compare(IF_DELIMITER) == 0){
                    ++it;
                    continue;
                }
                conditionTmp.push_back(*it);
                ++it;
            }
            m_conditions.push(conditionTmp);
            if ((*it).compare(BRACKET) == 0){
                commandsTmp.push_back(BRACKET);
                ++it;
            }
        }
        while ((*it).compare(IF_CHECK) && !(*it).empty()) {
            while ((*it).compare(IF_DELIMITER) && (*it).compare(CLOSING_BRACKET)){
                if ((*it).empty()){
                    continue;
                }
                commandsTmp.push_back(*it);
                ++it;
            }
            if ((*it).compare(IF_CHECK) == 0)
                continue;
            if ((*it).compare(CLOSING_BRACKET) == 0){
                commandsTmp.push_back(CLOSING_BRACKET);
                ++it;
            }
            if (!commandsTmp.empty()){
                m_commands.push(commandsTmp);
                commandsTmp.clear();
            }
            ++it;
        }
    }
    ifRecursion(m_commands,m_conditions,d);
    if (!(m_conditions.empty() & m_commands.empty()))
        cerr<<"If statement is incorrect!"<<endl;
    arguments.clear();
    Utils::clearQ(m_commands);
    Utils::clearQ(m_conditions);
    m_lp->setConditionLock(false);
}

int IfCommand::ifRecursion(queue<vector<string>> &commands,
                            queue<vector<string>> &conditions, Data *d) {
    int killCounter = 1;
    if (conditions.empty() && commands.empty())
        return 0;
    vector<string> commandVec = commands.front();
    commands.pop();
    if (commandVec.front().compare(BRACKET) == 0) {
        vector<string> conditionCheck = conditions.front();
        conditions.pop();
        if (Utils::checkCondition(conditionCheck,d)){
            conditions.push(conditionCheck);
            ifRecursion(commands,conditions,d);
        }
        else {
           while (killCounter) {
               commandVec = commands.front();
               commands.pop();
               if (commandVec.front().compare(BRACKET) == 0){
                   conditions.pop();
                   ++killCounter;
               } else if (commandVec.front().compare(CLOSING_BRACKET) == 0){
                   conditions.pop();
                   --killCounter;
               }
        }
           ifRecursion(commands,conditions,d);
    }

    } else if (commandVec.front().compare(CLOSING_BRACKET) == 0) {
        commands.pop();
        conditions.pop();
    } else {
        reverse(commandVec.begin(),commandVec.end());
        m_lp->Parser(commandVec);
        ifRecursion(commands,conditions,d);
    }
return 0;
}