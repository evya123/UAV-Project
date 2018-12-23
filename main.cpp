//
// Created by evya on 12/14/18.
//

#include <stdio.h>
#include "Expression/ShuntingYard.h"
#include <string>
#include <iostream>
#include "Commends/PrintCommand.h"
#include "Control/LexerParser.h"

int main() {
    Data *data = new Data();
    LexerParser *l = new LexerParser(data);
    string str = "var h0 = 2";
    l->LexerS(str);
    string str1 = "var h0 = h0 *8 ";
    l->LexerS(str1);
    string str2 = "var throttle =3";
    //l->LexerS(str2);

    PrintCommand *p = new PrintCommand();
    p->doCommand("this is a test");

    return 0;
}
