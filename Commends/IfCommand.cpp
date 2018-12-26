//
// Created by evya on 12/21/18.
//
#include "IfCommand.h"
<<<<<<< HEAD

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
=======
IfCommand::IfCommand() {

}

void IfCommand::doCommand(vector<string> &arguments, Data *d) {
    auto it = arguments.begin();

    vector<string> ifArgs {arguments.at(LHS),arguments.at(RHS)};
    double lhsD, rhsD;
    try {
        lhsD = stod(ifArgs[LHS]);
        rhsD = stod(ifArgs[RHS - 1]);
    } catch (invalid_argument ia) {
        cerr<<"Caught invalid_argument exception at IfCommand->doCommand: "<<ia.what()<<endl;
    }
    if (m_ac.getCondition(arguments[COMPARE])(lhsD,rhsD));
        printf("success");
>>>>>>> 50ccfc62480e0d460ea8805b27593848482a0288
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

