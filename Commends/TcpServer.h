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
#include <unistd.h>

#define MAXPACKETSIZE 1024

using namespace std;

class TcpServer {
public:
    TcpServer() = default;
    int openDataServer();
    void setup(int port);
    string receive();
    void detach();
    void clean();
private:

    static void* Task(void* argv);
    static string Message;
    int m_serverSocket, m_accVal;
    pthread_t m_serverThread;
    struct sockaddr_in m_serverAddress;
    struct sockaddr_in m_clientAddress;
};


#endif //UAV_PROJECT_TCPSERVER_H
