//
// Created by lidor115 on 12/21/18.
//

#include "MapStringCommand.h"
MapStringCommand::MapStringCommand() {
    //OpenData server command
    Command *openDataServer = new OpenDataServerCommand();
    _stringCommandMap.insert(pair<string, Command *>("openDataServer",
                                                     openDataServer));
    //Print Command
    Command *printCommand = new PrintCommand();
    _stringCommandMap.insert(pair<string, Command *>("print",
                                                     printCommand));
    //Connect Command
    Command *connectCommand = new ConnectCommand();
    _stringCommandMap.insert(pair<string, Command *>("connect",
            connectCommand));

    //VarCommand
    Command *varCommand = new VarCommand();
    _stringCommandMap.insert(pair<string, Command *>("var", varCommand));


}
>>>>>>> lidor-dev
