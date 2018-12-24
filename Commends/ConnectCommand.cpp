//
// Created by evya on 12/21/18.
//

#include "ConnectCommand.h"
ConnectCommand::ConnectCommand() {
    m_client = new TcpClient();
}

void ConnectCommand::doCommand(vector<string> &arguments, Data *d) {
    m_client->setup(arguments[IP_POS],stoi(arguments[PORT_POS_Client]));
    TcpClientStruct args;
    args.arg2 = m_client;
    args.arg1 = "set controls/flight/rudder 1";
    pthread_create(&m_clientThreadId, 0, &TcpClient::TaskClient, (void*)&args);
}

pthread_t ConnectCommand::getM_clientThreadId() const {
    return m_clientThreadId;
}

ConnectCommand::~ConnectCommand() {
    delete m_client;
}