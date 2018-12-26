//
// Created by evya on 12/21/18.
//

#include "WhileCommand.h"
void WhileCommand::doCommand(vector<string> &arguments, Data *d) {
    vector<string> ifArgs {arguments.at(LHS),arguments[COMPARE],
                           arguments.at(RHS), arguments[BRACKET_POS]};
    auto it = arguments.begin();
    vector<string> tmp;
    Utils::splitByDelimiter(it,BRACKET);
    while (Utils::checkCondition(ifArgs,d,m_brackets)) {
        while(it != arguments.end()){
            tmp = Utils::splitByDelimiter(it,IF_DELIMITER);
            auto tmpIt = tmp.begin();
            while(tmpIt != arguments.end()) {
                if ((*tmpIt).compare(BRACKET) == 0){
                    m_brackets.push(*it);
                    ++tmpIt;
                }
                if ((*tmpIt).compare(CLOSING_BRACKET) == 0){
                    m_brackets.pop();
                    ++tmpIt;
                }
                if (tmpIt != arguments.end())
                    //TODO: pass to lexer
                    ++tmpIt;
            }
            ++it;
        }
    }
}