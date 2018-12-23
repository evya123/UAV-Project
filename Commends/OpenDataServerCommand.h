//
// Created by evya on 12/17/18.
//

#ifndef DEV_OPENDATASERVERCOMMAND_H
#define DEV_OPENDATASERVERCOMMAND_H


#include "Command.h"
#include <stdexcept>
#include <Commends/PullAndPush/TcpServer.h>
#define PORT_POS 0
class OpenDataServerCommand : public Command {

public:
    OpenDataServerCommand();

    virtual void doCommand(vector<string> &arguments, Data *d);

    virtual ~OpenDataServerCommand();

private:
    int openDataServer(int port);
    int convertToInt(string port);

    TcpServer* m_server;
    string m_args;
};


#endif //DEV_OPENDATASERVERCOMMAND_H
