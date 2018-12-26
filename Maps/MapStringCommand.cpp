//
// Created by lidor115 on 12/21/18.
//

#include <cstring>
#include "MapStringCommand.h"

/**
 * initialize the map of the string and commands
 */
MapStringCommand::MapStringCommand(TcpClient *client, TcpServer *server) {
    //OpenData server command
    Command *openDataServer = new OpenDataServerCommand(server);
    _stringCommandMap.insert(pair<string, Command *>("openDataServer",
                                                     openDataServer));
    //Print Command
    Command *printCommand = new PrintCommand();
    _stringCommandMap.insert(pair<string, Command *>("print",
                                                     printCommand));
    //Connect Command
    Command *connectCommand = new ConnectCommand(client);
    _stringCommandMap.insert(pair<string, Command *>("connect",
                                                     connectCommand));

    //VarCommand
    Command *varCommand = new VarCommand();
    _stringCommandMap.insert(pair<string, Command *>("var", varCommand));

    //ifComnand
    Command *ifCommand = new IfCommand();

    _stringCommandMap.insert(pair<string, Command *>("if", ifCommand));


    //Enterc
    Command *whileCommand = new WhileCommand();
    _stringCommandMap.insert(pair<string, Command *>("while", whileCommand));
    Command *entercCommand = new EntercCommand();
    _stringCommandMap.insert(pair<string, Command *>("Enterc",
                                                     entercCommand));

}

MapStringCommand::~MapStringCommand() {
    // check if the map isn't empty
    if (!_stringCommandMap.empty()) {
        for (map<string, Command *>::iterator it = _stringCommandMap.begin();
             it != _stringCommandMap.end(); ++it) {
            //delete map and place null pointer;
            delete it->second;
            it->second = nullptr;
        }
    }
}

/**
 * get strign and return if the string represent a command or not.
 * @param c  - command (in string)
 * @return if the string represent a command or not
 */
bool MapStringCommand::isLeagalCommand(const string c) const {
    if (_stringCommandMap.count(c) > 0) {
        return true;
    }
    return false;
}

/**
 * get strign and return the command the string represent.
 * @param c  - command (in string)
 * @return the command the string represent if its illegal return nullptr
 */
Command *MapStringCommand::getCommand(const string c) const {
    return _stringCommandMap.at(c);

}