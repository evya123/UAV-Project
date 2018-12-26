//
// Created by evya on 12/20/18.
//

#include "TcpClient.h"

TcpClient::TcpClient(){
    sock = -1;
}

bool TcpClient::setup(string address , int port){
    cout<<"Client setup!"<<endl;
    if(sock == -1) {
        sock = socket(AF_INET , SOCK_STREAM , 0);
        if (sock < 0) {
            perror("TcpClient->setup: ");
            ::exit(EXIT_FAILURE);
        }
    }
    if(inet_addr(address.c_str()) == -1) {
        struct hostent *he;
        struct in_addr **addr_list;
        if ( (he = gethostbyname( address.c_str() ) ) == NULL) {
            herror("gethostbyname");
            cout<<"Failed to resolve hostname\n";
            return false;
        }
        addr_list = (struct in_addr **) he->h_addr_list;
        for(int i = 0; addr_list[i] != NULL; i++) {
            server.sin_addr = *addr_list[i];
            break;
        }
    } else {
        server.sin_addr.s_addr = inet_addr( address.c_str() );
    }
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    int connectRet;
    for (int j = 0; j <= 9 ; ++j) {
        if ((connectRet = connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0))
            sleep(1);
        else
            return true;
    }
    if (connectRet < 0){
        perror("TcpClient->setup: ");
        throw runtime_error ("Cannot connect to FlightGear, tried 10 times");
    }
}

bool TcpClient::Send(string &data){
    cout<<"Sending!"<<endl;
    if(sock != -1) {
        if(send(sock , data.c_str() , strlen( data.c_str() ) , NULL) < 0) {
            cout<<"Send failed :"<<data<<endl;
            return false;
        }
    } else {
        cout<<"Socket is not initialized"<<endl;
        return false;
    }
return true;
}

void TcpClient::exit(){
    shutdown(sock,SHUT_RDWR); //stop connection from both sides but can still receive pending data
    sleep(1);               //let the pending data flow and then close
    close(sock);
}