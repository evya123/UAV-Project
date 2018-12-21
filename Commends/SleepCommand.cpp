//
// Created by evya on 12/21/18.
//

#include "SleepCommand.h"

void SleepCommand::doCommand(const string &arguments) {
    sleep(stoi(arguments));
}
