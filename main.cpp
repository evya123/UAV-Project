//
// Created by evya on 12/14/18.
//

#include <stdio.h>
#include <Commends/OpenDataServerCommand.h>
#include <Commends/ConnectCommand.h>

<<<<<<< HEAD
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


=======
int main(int argc, char* argv[]) {
    Data* data = new Data();
    LexerParser* l = new LexerParser(data);
    l->ReadFromFile(argv[1]);
>>>>>>> a4c13783560741106899eabbf29cbcb760faab00
return 0;
}
