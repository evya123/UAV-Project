//
// Created by evya on 12/18/18.
//

#ifndef UAV_PROJECT_TCPSERVER_H
#define UAV_PROJECT_TCPSERVER_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <stdexcept>

using namespace std;

class TcpServer {
public:
    TcpServer() = default;
    static void* Task();
    int openDataServer();
    void setup(int port);
    string receive();

private:
    int m_serverSocket, m_accVal;
    pthread_t m_serverThread;
    struct sockaddr_in m_serverAddress;
    struct sockaddr_in m_clientAddress;
};


#endif //UAV_PROJECT_TCPSERVER_H
