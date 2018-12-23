//
// Created by evya on 12/14/18.
//

#include <stdio.h>
#include "Expression/ShuntingYard.h"
#include <string>
#include <iostream>
#include "Commends/PrintCommand.h"
#include "Control/LexerParser.h"
#include "Commends/ArithmeticConditions.h"
#include "Commends/PullAndPush/TcpServer.h"

void toMap(string toSplit) {
    vector<float> f;
    size_t pos = 0;
    string token;
    while ((pos = toSplit.find(DELIMITER)) != string::npos) {
        token =toSplit.substr(0, pos);
        f.push_back(stof(token));
        toSplit.erase(0, pos + 1);
        cout<<token<<endl;
    }
}

void* p(void*){
    while(true){
        sleep(5);
        cout<<"test\n"<<endl;
    }
}

int main() {
//
//    string s = "0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000";
//    toMap(s);

TcpServer* t = new TcpServer();
t->setup(5400);
pthread_t id, id2;
int ret =t->receive();
pthread_create(&id,NULL, &TcpServer::task,(void *)ret);
//pthread_create(&id2,NULL,&p,(void*)0);
pthread_join(id,NULL);
//pthread_join(id2,NULL);
//    Data * data = new Data();
//    LexerParser *l = new LexerParser(data);
//    string s1 = "var x = 5";
//    l->LexerS(s1);
//    string s2 = "var y = x* 5 *8 -2";
//    l->LexerS(s2);

//test();
//PrintCommand* p = new PrintCommand();
//    vector<string> a {"this","is","a","test"};
//p->doCommand(a);
//SleepCommand * s = new SleepCommand();
//vector<string> b = {"5"};
//s->doCommand(b);
//p->doCommand(a);
return 0;
}
