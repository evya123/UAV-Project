
#include "OpenDataServerCommand.h"
OpenDataServerCommand::OpenDataServerCommand(TcpServer *server) {
    m_server = server;
}

void OpenDataServerCommand::doCommand(vector<string> &arguments, Data *d) {
    cout<<"OpenDataServerCommand!"<<endl;
    int port = fromStringToNum(arguments.back(), INTEGER);
    arguments.clear();
    TcpStruct args;
    m_server->setup(port);
    args.arg1 = m_server->receive();
    args.arg2 = d;
    thread dataServer(TcpServer::TaskServer,&args);

    dataServer.detach();
}

OpenDataServerCommand::~OpenDataServerCommand() {
    delete m_server;
}



