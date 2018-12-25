//
// Created by lidor115 on 12/21/18.
//

#include "Commends/PrintCommand.h"
#include "Commends/ConnectCommand.h"
#include "Commends/SleepCommand.h"
#include "Commends/VarCommand.h"
#include "Commends/OpenDataServerCommand.h"
#include "Commends/IfCommand.h"
#include "Commends/WhileCommand.h"
#include "Commends/EntercCommand.h"

#include <map>

using namespace std;
#ifndef UAV_PROJECT_MAPSTRINGCOMMAND_H
#define UAV_PROJECT_MAPSTRINGCOMMAND_H

class MapStringCommand {
    map<string, Command *> _stringCommandMap;
public:
    MapStringCommand();

    bool isLeagalCommand(const string c) const;

    ~MapStringCommand();

    Command *getCommand(const string c) const;
};

#endif //UAV_PROJECT_MAPSTRINGCOMMAND_H
