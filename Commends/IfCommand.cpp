//
// Created by evya on 12/21/18.
//

#include "IfCommand.h"

IfCommand::IfCommand() {
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
            auto tmpIt = tmp.begin();
            while(tmpIt != arguments.end()) {
                if ((*tmpIt).compare(BRACKET) == 0){
                    m_brackets.push(*it);
                    ++tmpIt;
                } else if ((*tmpIt).compare(CLOSING_BRACKET) == 0){
                    m_brackets.pop();
                    ++tmpIt;
                }
                if (tmpIt != arguments.end())
                    //TODO
                ++tmpIt;
            }
            ++it;
        }
    }
    if(!m_brackets.empty())
        cerr<<"If syntax is incorrect!"<<endl;
}
