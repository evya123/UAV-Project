//
// Created by evya on 12/14/18.
//

#include <stdio.h>
#include <Commends/OpenDataServerCommand.h>
#include <Commends/ConnectCommand.h>
int main() {
    OpenDataServerCommand* pdsc = new OpenDataServerCommand();
    ConnectCommand* cc = new ConnectCommand();
    vector<string> serverC {"5400"};
    vector<string> clientC {"172.16.20.102", "5402"};
    Data* a = new Data();
    pdsc->doCommand(serverC,a);
    cc->doCommand(clientC,a);
    pthread_join(pdsc->getId(),NULL);
    pthread_join(cc->getM_clientThreadId(),NULL);
    while(true){
        cout<<"This is also a test in main"<<endl;
    }
return 0;
}
