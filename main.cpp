//
// Created by evya on 12/14/18.
//

#include <stdio.h>
#include "ShuntingYard.h"
#include <string>
#include <iostream>

#include "Commends/TcpServer.h"
#include "Commends/TcpClient.h"



int main(){

TcpClient* tcpC = new TcpClient();
tcpC->setup("172.16.20.103",12345);
tcpC->Send("Hello");
return 0;
}
