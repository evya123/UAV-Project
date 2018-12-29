
#include "OpenDataServerCommand.h"

OpenDataServerCommand::OpenDataServerCommand(TcpServer *server) {
    m_server = server;
}

void OpenDataServerCommand::doCommand(vector<string> &arguments, Data *d) {
    cout << "OpenDataServerCommand!" << endl;
    int port = stod(arguments.back());
    arguments.clear();
    TcpStruct* args = new  TcpStruct();
    args->arg1 = m_server->setup(port);
    args->arg2 = d;
    thread dataServer(TcpServer::TaskServer,args->arg1, d);

    dataServer.detach();
}

OpenDataServerCommand::~OpenDataServerCommand() {
    delete m_server;
}