//
// Created by evya on 12/21/18.
//

#include "SleepCommand.h"

void SleepCommand::doCommand(vector<string> &arguments, Data *d) {

    double msec = Utils::calculateExpression(arguments.back(),d);
    this_thread::sleep_for(chrono::milliseconds(static_cast<int>(msec)));
    usleep(msec);
    arguments.clear();
    }
