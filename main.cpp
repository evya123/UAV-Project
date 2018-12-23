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

vector<string> splitByDelimiter(vector<string>::iterator& it,const string delimiter) {
    vector<string> ret;
    while((*it).compare(delimiter) != 0){
        ret.push_back((*it));
        ++it;
    }
    return ret;
}

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
return 0;
}
