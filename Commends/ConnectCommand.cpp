//
// Created by evya on 12/21/18.
//

#include "ConnectCommand.h"
ConnectCommand::ConnectCommand() {
    m_client = new TcpClient();
}

void ConnectCommand::doCommand(vector<string> &arguments, Data *d) {
    m_client->setup(arguments[IP_POS],stoi(arguments[PORT_POS_Client]));
    arguments.clear();
}

pthread_t ConnectCommand::getM_clientThreadId() const {
    return m_clientThreadId;
}

ConnectCommand::~ConnectCommand() {
    delete m_client;
}