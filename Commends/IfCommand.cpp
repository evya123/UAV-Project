//
// Created by evya on 12/21/18.
//
/**
#include "IfCommand.h"
IfCommand::IfCommand(MapStringCommand *mpc) {
    m_msc = mpc;
}

<<<<<<< HEAD
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
=======
void IfCommand::doCommand(vector<string> &arguments, Data *d) {
    if(nblalalala) {
        auto it = arguments.begin();
        while((*it) != ";")
            docommands(vector)
    }
}
**/
>>>>>>> e24b11e7c9b5be89e91e4fcd3751b1ba2fb6f871
