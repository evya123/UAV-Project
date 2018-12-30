//
// Created by evya on 12/18/18.
//

#ifndef UAV_PROJECT_TCPSERVER_H
#define UAV_PROJECT_TCPSERVER_H

#include <cstring>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <Maps/Data.h>
#include "XmlFormat.h"
#include "Commends/Command.h""
#include "Utils.h"

#define MAXPACKETSIZE 256

using namespace std;

class TcpServer {
public:
    TcpServer() = default;

    int setup(int port);

  //  int receive();

    void detach();


    static void *TaskServer(int soc, Data *data);
    void toMap(string toSplit);



private:
    int m_serverSocket, m_accVal;
    struct sockaddr_in m_serverAddress;
    struct sockaddr_in m_clientAddress;
};

typedef struct arg_struct_server {
    int arg1;
    Data *arg2;
} TcpStruct;

#endif //UAV_PROJECT_TCPSERVER_H
