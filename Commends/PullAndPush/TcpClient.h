//
// Created by evya on 12/20/18.
//

#ifndef UAV_PROJECT_TCPCLIENT_H
#define UAV_PROJECT_TCPCLIENT_H




#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

using namespace std;
struct arg_struct_client;
class TcpClient
{
private:
    int sock;
    struct sockaddr_in server;


public:
    TcpClient();
    bool setup(string address, int port);
    bool Send(string &data);
    static void* TaskClient(void *);
    void start(pthread_t &id, arg_struct_client &args);
    void exit();
};

typedef struct arg_struct_client {
    string arg1;
    TcpClient* arg2;
}TcpClientStruct;

#endif //UAV_PROJECT_TCPCLIENT_H
