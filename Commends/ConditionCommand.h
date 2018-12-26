//
// Created by lidor115 on 12/26/18.
//

#ifndef UAV_PROJECT_CONDITIONCOMMAND_H
#define UAV_PROJECT_CONDITIONCOMMAND_H

#include "Command.h"
#include "Maps/MapStringCommand.h"
#include "Utils.h"

class ConditionCommmand : public Command {
private:
    Data *_data;
    MapStringCommand *_mapStringCommand;
    string _numOfBrackets;
    map<string, Command *> commandsToDo;
protected:
    ConditionCommmand(Data *data, MapStringCommand *mapStringCommand);

    void CommandParser(vector<string> &commands, vector<string> &arguments);

    void ConditionParser(vector<string> &arguments);

    bool checkCondition(vector<string> &arguments);

};

#endif //UAV_PROJECT_CONDITIONCOMMAND_H
