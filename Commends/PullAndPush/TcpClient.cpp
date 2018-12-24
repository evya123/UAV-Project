//
// Created by evya on 12/20/18.
//

#include "TcpClient.h"
#include "TcpServer.h"

TcpClient::TcpClient(){
    sock = -1;
}

bool TcpClient::setup(string address , int port){

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
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0) {
        perror("TcpClient->setup: ");
        return false;
    }
    return true;
}

bool TcpClient::Send(string data){
    if(sock != -1) {
        if(send(sock , data.c_str() , strlen( data.c_str() ) , 0) < 0) {
            printf("Send failed : %s" ,&data);
            return false;
        }
    } else {
        printf("Socket is not initialized");
        return false;
    }
return true;
}

void TcpClient::exit(){
    shutdown(sock,SHUT_RDWR); //stop connection from both sides but can still receive pending data
    sleep(1); //let the pending data flow and then close
    close(sock);
}

//void TcpClient::start(pthread_t &id, arg_struct_client &args) {
//    pthread_create(&id, 0, &TcpClient::TaskClient, (void*)&args);
//}

void* TcpClient::TaskClient(void *arg) {
    TcpClientStruct *args = static_cast<TcpClientStruct*>(arg);
    TcpClient* _this = args->arg2;
    _this->Send(args->arg1);
//    int i = 5;
//    while(i != 0){
//        cout<<"this is just a test in client!: "<<args->arg1<<endl;
//        sleep(1);
//        --i;
//    }
    pthread_exit(0);
}