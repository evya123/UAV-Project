//
// Created by evya on 12/18/18.
//
#include "TcpServer.h"
#include <iostream>
#include <fstream>
/**
 * Function name: setup
 * @param port
 * @param ip
 * The function initialize the server arguments, create the socket,
 * bind the socket to the port and ip and the make the server
 * listen to the port and wait for connection.
 */
void TcpServer::setup(int port) {
    m_serverSocket = socket(AF_INET,SOCK_STREAM,0); //Create the socket
    if (m_serverSocket < 0){ //Check if the creation succeeded
        perror("OpenDataServerCommand->setup: ");
        exit(EXIT_FAILURE);
    }
    memset(&m_serverAddress,0, sizeof(m_serverAddress)); //allocate space for the struct and put zeros
    m_serverAddress.sin_family = AF_INET;
    m_serverAddress.sin_addr.s_addr=htonl(INADDR_ANY); //Convert '0.0.0.0' to network byte order. set to any ip because the server
                                                        //doesn't know the client ip and doesn't need to.
    m_serverAddress.sin_port = htons(port);
    ::bind(m_serverSocket,(sockaddr*)&m_serverAddress, sizeof(m_serverAddress)); //:: before bind because without it, the function use std::bind
    int lst = listen(m_serverSocket,5);
    if (lst < 0) {
        perror("OpenDataServerCommand->setup: ");
        close(m_serverSocket);
        exit(EXIT_FAILURE);
    }
}


void * TcpServer::TaskServer(void *arg) {
    TcpStruct *args = static_cast<TcpStruct*>(arg);
    int newsockfd = args->arg1;
    Data* d = args->arg2;
    int n;
    char msg[MAXPACKETSIZE];
    while(true)
    {
        memset(msg,0,MAXPACKETSIZE);
        n=recv(newsockfd,msg,MAXPACKETSIZE,0);
        toMap(string(msg),d);
        if(n==0) {
            close(newsockfd);
            break;
        }
        cout<<"this is just a test in server!: "<<msg<<endl;
        sleep(TIME_TO_WAIT);
    }
    pthread_exit(0);
}

/**
 * Function name: receive
 * @return return the msg the client sent
 * Function open a while loop and wait for client to connect.
 * Upon connection, accept the connection and create a thread
 * which runs Task().
 **/
int TcpServer::receive() {
    //string str;
    socklen_t sosize  = sizeof(m_clientAddress);
    m_accVal = accept(m_serverSocket,(struct sockaddr*)&m_clientAddress,&sosize); //On success, these system calls return a nonnegative integer that is a
        //file descriptor for the accepted socket.  On error, -1 is returned,
        //and errno is set appropriately.
    return m_accVal;
}


/**
 * Close the socket
 */
void TcpServer::detach()
{
    shutdown(m_serverSocket,SHUT_RDWR);
    shutdown(m_accVal,SHUT_RDWR);
    sleep(1);
    close(m_serverSocket);
    close(m_accVal);
}

void TcpServer::toMap(string toSplit, Data *d) {
    map<string,double> toSave;
    auto it = m_xmlHandler.begin();
    size_t pos = 0;
    while (toSplit != "") {
        if(++it == m_xmlHandler.end())
            break;
        pos = toSplit.find(DELIMITER);
        toSave.insert(make_pair(*it,stod(toSplit.substr(0, pos))));
        toSplit.erase(0, pos + 1);
        if(++it == m_xmlHandler.end())
            break;
    }

}