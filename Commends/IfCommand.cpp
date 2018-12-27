//
// Created by evya on 12/21/18.
//

#include "IfCommand.h"

IfCommand::IfCommand(LexerParser *lp) {
    m_lp = lp;
}

void IfCommand::doCommand(vector<string> &arguments, Data *d) {
    vector<string> ifArgs {arguments.at(LHS),arguments[COMPARE],
                           arguments.at(RHS), arguments[BRACKET_POS]};
    auto it = arguments.begin();
    vector<string> tmp;
    Utils::splitByDelimiter(it,BRACKET);
    if(Utils::checkCondition(ifArgs,d,m_brackets)) {
        while(it != arguments.end()){
            tmp = Utils::splitByDelimiter(it,IF_DELIMITER);
            if (tmp.empty())
                continue;
            auto tmpIt = tmp.begin();
            if(tmp.back().compare(BRACKET) == 0) {
                m_brackets.push(BRACKET);
                tmp.pop_back();
                ++tmpIt;
            }
            if(tmp.back().compare(CLOSING_BRACKET) == 0) {
                m_brackets.pop();
                tmp.pop_back();
                ++tmpIt;
            }
            reverse(tmp.begin(),tmp.end());
            if (tmpIt != arguments.end())
                m_lp->Parser(tmp);
            if ((*it).compare(BRACKET) == 0){
                m_brackets.push(*it);
                ++it;
            } else if ((*it).compare(CLOSING_BRACKET) == 0){
                m_brackets.pop();
                ++it;
            }
        }
    }
    if(!m_brackets.empty())
        cerr<<"If syntax is incorrect!"<<endl;
}

