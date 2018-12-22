//
// Created by evya on 12/21/18.
//

#include "SleepCommand.h"

void SleepCommand::doCommand(const vector<string> arguments) {
    sleep(stoi(arguments.at(SLEEP_TIME)));
}
