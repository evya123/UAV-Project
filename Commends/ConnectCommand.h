//
// Created by evya on 12/21/18.
//

#ifndef UAV_PROJECT_CONNECTCOMMAND_H
#define UAV_PROJECT_CONNECTCOMMAND_H

#include "Command.h"
#include <iostream>
#include <Commends/PullAndPush/TcpClient.h>
#define IP_POS 0
#define PORT_POS_Client 1

class ConnectCommand : public Command{

public:
    ConnectCommand();
    virtual void doCommand(vector<string> &arguments, Data *d);
    virtual ~ConnectCommand();

    pthread_t getM_clientThreadId() const;

private:
    pthread_t m_clientThreadId;
    TcpClient* m_client;
};


#endif //UAV_PROJECT_CONNECTCOMMAND_H
