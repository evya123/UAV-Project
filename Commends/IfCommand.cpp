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
        if ((*it).compare(IF_CHECK) == 0 || (*it).compare(WHILE_CHECK) == 0) {
            vector<string> conditionTmp;
            while ((*it).compare(BRACKET)) {
                if ((*it).compare(SEMICOLON) == 0) {
                    ++it;
                    continue;
                }
                conditionTmp.push_back(*it);
                ++it;
            }
            m_conditions.push(conditionTmp);
            if ((*it).compare(BRACKET) == 0) {
                commandsTmp.push_back(BRACKET);
                ++it;
            }
        }
        while (it != arguments.end()) {
            if ((*it).compare(IF_CHECK) == 0 ||
                (*it).compare(WHILE_CHECK) == 0) {
                break;
            }
            while ((*it).compare(SEMICOLON) &&
                   (*it).compare(CLOSING_BRACKET)) {
                if ((*it).empty()) {
                    continue;
                }
                commandsTmp.push_back(*it);
                ++it;
            }
            if ((*it).compare(IF_CHECK) == 0 ||
                (*it).compare(WHILE_CHECK) == 0)
                continue;
            if ((*it).compare(CLOSING_BRACKET) == 0) {
                commandsTmp.push_back(CLOSING_BRACKET);
                ++it;
            }
            if (!commandsTmp.empty()) {
                m_commands.push(commandsTmp);
                commandsTmp.clear();
            }
            ++it;
        }
    }
    //////
    vector<string> tempCondition;
    tempCondition = m_conditions.front();
        Utils::LoopCommand(m_commands, m_conditions, d, m_lp);

    printf ("Done!");
/*
    if (!(m_conditions.empty() & m_commands.empty()))
        cerr << "If statement is incorrect!" << endl;
        */
    arguments.clear();
    Utils::clearQ(m_commands);
    Utils::clearQ(m_conditions);
    m_lp->setConditionLock(false);
}
