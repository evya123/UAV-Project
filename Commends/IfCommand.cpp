//
// Created by evya on 12/21/18.
//
#include "IfCommand.h"

void IfCommand::doCommand(vector<string> &arguments, Data *d) {
    vector<Command *> commands;
    try {
        if (this->checkCondition(arguments)) {
            for (unsigned long int i = 0;i<commands.size(); i++){
                commands.at(i)->doCommand()
        }

    }
}

/**
auto it = arguments.begin();
LexerParser lp(d);
vector<string> ifArgs {arguments.at(LHS),arguments.at(RHS)};
if (m_ac.getCondition(arguments[COMPARE])(stod(ifArgs[LHS]),stod(ifArgs[RHS - 1])))
    printf("success");
    **/
}

vector<string> IfCommand::splitByDelimiter(vector<string>::iterator &it,
                                           const string delimiter) {
    vector<string> ret;
    while ((*it).compare(delimiter) != 0) {
        ret.push_back((*it));
        ++it;
    }
    ++it;
    return ret;
}

