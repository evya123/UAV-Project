//
// Created by evya on 12/20/18.
//

#ifndef UAV_PROJECT_TCPCLIENT_H
#define UAV_PROJECT_TCPCLIENT_H




#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netdb.h>
#include <vector>

using namespace std;

class TcpClient
{
private:
    int sock;
    string address;
    int port;
    struct sockaddr_in server;

public:
    TcpClient();
    bool setup(string address, int port);
    bool Send(string data);
    string receive(int size = 4096);
    string read();
    void exit();
};

#endif //UAV_PROJECT_TCPCLIENT_H
