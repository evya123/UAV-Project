//
// Created by lidor115 on 12/21/18.
//

#include "OpenDataServerCommand.h"
#include "Command.h"
#include <map>
using namespace std;
#ifndef UAV_PROJECT_MAPSTRINGCOMMAND_H
#define UAV_PROJECT_MAPSTRINGCOMMAND_H
class MapStringCommand{
    map<string, Command*> _stringCommandMap;
public:
    MapStringCommand();
};
#endif //UAV_PROJECT_MAPSTRINGCOMMAND_H
