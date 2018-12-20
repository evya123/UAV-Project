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
//    string str = " ( -2 * - 3 ) + - 5  * - 5";
//    ShuntingYard s(str);
//    cout << s.evaluate () << "\n";

TcpClient* tcpC = new TcpClient();
tcpC->setup("172.16.20.103",12345);
tcpC->Send("Hello");
return 0;
}