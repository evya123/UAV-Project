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

int main(int argc, char *argv[]){

    Data * data = new Data();
    LexerParser *l = new LexerParser(data);
    l->ReadFromFile(argv[1]);

//test();
//PrintCommand* p = new PrintCommand();
//    vector<string> a {"this","is","a","test"};
//p->doCommand(a);
//SleepCommand * s = new SleepCommand();
//vector<string> b = {"5"};
//s->doCommand(b);
//p->doCommand(a);

string a = "5.12345",b = "5.12345";
ArithmeticConditions* p = new ArithmeticConditions();
cout<<p->getCondition("!=")(65,5.5)<<endl;
return 0;
}
