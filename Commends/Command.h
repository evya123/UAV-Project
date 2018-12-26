
#ifndef DEV_COMMAND_H
#define DEV_COMMAND_H
#include <vector>
#include <Maps/Data.h>

using namespace std;

class Command {
public:
    virtual void doCommand(vector<string> &arguments, Data *d) = 0;
    virtual ~Command(){};
};

#endif //DEV_COMMAND_H
