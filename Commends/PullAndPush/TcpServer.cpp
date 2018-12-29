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
int TcpServer::setup(int port) {
    int opt = 1;
    struct sockaddr_in server, client;

    // Creating socket file descriptor
    if ((m_serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(m_serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt,
                   sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);

    // Forcefully attaching socket to the port 8080
    if (bind(m_serverSocket, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(m_serverSocket, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    socklen_t addrlen = sizeof(sockaddr_in);
    m_accVal = accept(m_serverSocket, (struct sockaddr *) &client, &addrlen);
    if (m_accVal < 0) {
        cout << "Error!" << endl;
    } else
        cout << "Connection accepted, starting listener thread" << endl;
    char buf;
    read(m_accVal, &buf, 1);
    return m_accVal;
}


void *TcpServer::TaskServer(int soc, Data *data) {
    cout << "Connected! now waiting for data!" << endl;
    int newsockfd = soc;
    int n;
    cout << "the soc is: " << n << endl;

    char msg[MAXPACKETSIZE];
    while (true) {
        memset(msg, 0, MAXPACKETSIZE);
        n = read(newsockfd, msg, MAXPACKETSIZE);
        if (msg != "")
            cout << msg << endl;
        data->toMap(string(msg));
        if (n == 0) {
            close(newsockfd);
            break;
        }
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


/**
 * Close the socket
 */
void TcpServer::detach() {
    if (shutdown(m_serverSocket, SHUT_RDWR) != 0) {
        perror("TcpServer->detach->shutdown 1: ");
    } else if (shutdown(m_accVal, SHUT_RDWR) != 0) {
        perror("TcpServer->detach->shutdown 2: ");
    }
    sleep(1);
    if (close(m_serverSocket) != 0) {
        perror("TcpServer->detach->close 1: ");
    }
}
