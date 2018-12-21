
#ifndef DEV_COMMAND_H
#define DEV_COMMAND_H
#include <string>

using namespace std;

class Command {
    virtual void doCommand(string arguments) = 0;
};

#endif //DEV_COMMAND_H
