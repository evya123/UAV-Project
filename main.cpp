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

int main() {

    Data * data = new Data();
    LexerParser *l = new LexerParser(data);
    string s1 = "var x = 5";
    l->LexerS(s1);
    string s2 = "var y = x* 5 *8 -2";
    l->LexerS(s2);

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
