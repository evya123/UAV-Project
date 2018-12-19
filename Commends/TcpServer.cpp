//
// Created by evya on 12/18/18.
//

#include "TcpServer.h"

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
        perror("OpenDataServerCommand->openDataServer: ");
        exit(EXIT_FAILURE);
    }
    memset(&m_serverAddress,0, sizeof(m_serverAddress)); //allocate space for the struct
    m_serverAddress.sin_family = AF_INET;
    m_serverAddress.sin_addr.s_addr=htonl(INADDR_ANY); //Convert '0.0.0.0' to network byte order. set to any ip because the server
    //doesn't know the client ip and doesn't need to.
    m_serverAddress.sin_port = htons(port);
    ::bind(m_serverSocket,(sockaddr*)&m_serverAddress, sizeof(m_serverAddress)); //:: before bind because without it, the function use std::bind
    int lst = listen(m_serverSocket,5);
    if (lst < 0) {
        perror("OpenDataServerCommand->setup: ");
        exit(EXIT_FAILURE);
    }
}

string TcpServer::receive() {
    string str;
    while(true)
    {
        socklen_t sosize  = sizeof(m_clientAddress);
        m_accVal = accept(m_serverSocket,(struct sockaddr*)&m_clientAddress,&sosize);
        str = inet_ntoa(m_clientAddress.sin_addr);
        //pthread_create(&m_serverThread,NULL,NULL,(void *)m_accVal);
    }
    return str;
}