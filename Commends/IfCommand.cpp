//
// Created by evya on 12/21/18.
//

#include "IfCommand.h"
IfCommand::IfCommand(MapStringCommand *mpc) {
    m_msc = mpc;
}

void IfCommand::doCommand(const vector<string> &arguments, Data &d) {
    auto it = arguments.begin();
    LexerParser lp(&d);
    vector<string> ifArgs {arguments[LHS],arguments[RHS]};
    lp.varOperation(ifArgs);
    if (m_ac.getCondition(arguments[COMPARE])(stod(ifArgs[LHS]),stod(ifArgs[RHS - 1]))) {
        printf("success");
    }
}

vector<string> IfCommand::splitByDelimiter(vector<string>::iterator& it,const string delimiter) {
    vector<string> ret;
    while((*it).compare(delimiter) != 0){
        ret.push_back((*it));
        ++it;
    }
    ++it;
    return ret;
}