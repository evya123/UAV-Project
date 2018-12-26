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
#include <iostream>
#include <vector>
#include <Maps/Data.h>
#include "XmlFormat.h"
#include <Commends/Command.h>

#define DELIMITER ','

#define MAXPACKETSIZE 1024

using namespace std;

class TcpServer {
public:
    TcpServer() = default;
    void setup(int port);
    int receive();
    void detach();

    static void *TaskServer(void *arg);

private:
    static void toMap(string toSplit, Data *d);
    int m_serverSocket, m_accVal;
    struct sockaddr_in m_serverAddress;
    struct sockaddr_in m_clientAddress;

};

typedef struct arg_struct_server {
    int arg1;
    Data* arg2;
}TcpStruct;

#endif //UAV_PROJECT_TCPSERVER_H
