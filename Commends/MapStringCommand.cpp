//
// Created by lidor115 on 12/21/18.
//

#include "MapStringCommand.h"
#include "

MapStringCommand::MapStringCommand() {
    Command* openDataServer = new OpenDataServerCommand();
    _stringCommandMap.insert(pair<string, Command *>("openDataServer",
            openDataServer));
    Command* printCommand = new
    _stringCommandMap.insert("print", )
}