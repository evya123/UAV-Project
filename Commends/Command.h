
#ifndef DEV_COMMAND_H
#define DEV_COMMAND_H
#include <string>
#include <vector>

using namespace std;

class Command {
public:
    virtual void doCommand(const vector<string> &arguments, Date &d) = 0;
    virtual ~Command(){};
};

#endif //DEV_COMMAND_H
