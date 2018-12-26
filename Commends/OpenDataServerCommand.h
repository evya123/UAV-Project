//
// Created by evya on 12/17/18.
//

#ifndef DEV_OPENDATASERVERCOMMAND_H
#define DEV_OPENDATASERVERCOMMAND_H


#include "Command.h"
#include <stdexcept>
#include <Commends/PullAndPush/TcpServer.h>
#include <thread>

class OpenDataServerCommand : public Command {

public:

    OpenDataServerCommand(TcpServer *server);

    virtual void doCommand(vector<string> &arguments, Data *d);

    virtual ~OpenDataServerCommand();
private:
    TcpServer* m_server;
    int convertToInt(string port);
    string m_args;
};


#endif //DEV_OPENDATASERVERCOMMAND_H
