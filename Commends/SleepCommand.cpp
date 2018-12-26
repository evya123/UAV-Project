//
// Created by evya on 12/21/18.
//

#include "SleepCommand.h"

void SleepCommand::doCommand(vector<string> &arguments, Data *d) {
    usleep(Utils::fromStringToNum(arguments.at(SLEEP_TIME), DOUBLE));
    arguments.clear();
}
