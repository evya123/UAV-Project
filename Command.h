
#ifndef DEV_COMMAND_H
#define DEV_COMMAND_H
#include <string>

using namespace std;

class Command {
    virtual void doCommand() = 0;
};

#endif //DEV_COMMAND_H
