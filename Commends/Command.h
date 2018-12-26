
#ifndef DEV_COMMAND_H
#define DEV_COMMAND_H
#include <string>
#include <vector>
#include <Maps/Data.h>

using namespace std;
#define INTEGER "i"
#define DOUBLE "d"

class Command {
public:
    virtual void doCommand(vector<string> &arguments, Data *d) = 0;
    static int fromStringToNum(string &str, const string &type);
    virtual ~Command(){};
};

int Command::fromStringToNum(string &str, const string &type) {
    try {
        if(type.compare(INTEGER) == 0)
            return stoi(str);
        if(type.compare(DOUBLE) == 0)
            return stod(str);
    } catch(invalid_argument& e){
        // if no conversion could be performed
        printf("OpenDataServerCommand->fromStringToNum: %s", e.what());
        exit(EXIT_FAILURE);
    } catch(out_of_range& e){
        // if the converted value would fall out of the range of the result type
        // or if the underlying function (std::strtol or std::strtoull) sets errno
        // to ERANGE.
        printf("OpenDataServerCommand->fromStringToNum: %s", e.what());
        exit(EXIT_FAILURE);
    } catch(exception& e) {
        // everything else
        printf("OpenDataServerCommand->fromStringToNum: %s", e.what());
        exit(EXIT_FAILURE);
    }
}

#endif //DEV_COMMAND_H
