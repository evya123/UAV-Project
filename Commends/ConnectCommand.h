//
// Created by evya on 12/21/18.
//

#ifndef UAV_PROJECT_CONNECTCOMMAND_H
#define UAV_PROJECT_CONNECTCOMMAND_H

#include "Command.h"
#include <iostream>
#include <Commends/PullAndPush/TcpClient.h>
#define PORT_POS_Client 0
#define IP_POS 1

class ConnectCommand : public Command{

public:
    ConnectCommand(TcpClient*);
    virtual void doCommand(vector<string> &arguments, Data *d);
    virtual ~ConnectCommand();

private:

    TcpClient* m_client;
};


#endif //UAV_PROJECT_CONNECTCOMMAND_H
