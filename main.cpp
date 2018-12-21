//
// Created by evya on 12/14/18.
//

#include <stdio.h>
#include "ShuntingYard.h"
#include <string>
#include <iostream>
#include "Commends/TcpServer.h"
#include "Commends/TcpClient.h"

using namespace std;




int main(){

    TcpServer* tcp = new TcpServer();
    tcp->setup(5400);
    tcp->receive();
    tcp->detach();
    return 0;
}