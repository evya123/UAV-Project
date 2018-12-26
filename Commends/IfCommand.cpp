//
// Created by evya on 12/21/18.
//
#include "IfCommand.h"
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

