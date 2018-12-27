//
// Created by evya on 12/17/18.
//

#ifndef DEV_OPENDATASERVERCOMMAND_H
#define DEV_OPENDATASERVERCOMMAND_H

#include <Commends/PullAndPush/TcpServer.h>
#include <stdexcept>
#include <thread>
class TcpServer;

class OpenDataServerCommand : public Command {

public:

    OpenDataServerCommand(TcpServer *server);

    virtual void doCommand(vector<string> &arguments, Data *d);

    virtual ~OpenDataServerCommand();
private:
    TcpServer* m_server;
};


#endif //DEV_OPENDATASERVERCOMMAND_H
