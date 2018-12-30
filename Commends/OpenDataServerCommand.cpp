
#include "OpenDataServerCommand.h"

OpenDataServerCommand::OpenDataServerCommand(TcpServer *server) {
    m_server = server;
}

void OpenDataServerCommand::doCommand(vector<string> &arguments, Data *d) {
    cout << "OpenDataServerCommand!" << endl;
    int port = stod(arguments.back());
    arguments.clear();
    int socfd = m_server->setup(port);
    thread dataServer(TcpServer::TaskServer,socfd, d);

    dataServer.detach();
}
