//
// Created by evya on 12/21/18.
//

#include "ConnectCommand.h"
ConnectCommand::ConnectCommand(TcpClient* client) {
    m_client = client;
}

void ConnectCommand::doCommand(vector<string> &arguments, Data *d) {
    cout<<"ConnectCommand!"<<endl;
    int port = fromStringToNum(arguments[PORT_POS_Client], INTEGER);
    m_client->setup(arguments[IP_POS],port);
    arguments.clear();
}

ConnectCommand::~ConnectCommand() {
    delete m_client;
}