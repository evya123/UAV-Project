//
// Created by evya on 12/14/18.
//

#include <stdio.h>
#include "ShuntingYard.h"
#include <string>
#include <iostream>
#include <vector>
#include "LexerParser.h"

int main(int argc, char *argv[]) {

    string c = "";
    for (int i = 1; i < argc; i++) {
        c += argv[i];
        c += " ";
    }
    vector<string> lex = LexerS(c);
    string str = " ( -2 * - 3 ) + - 5  * - 5";
    ShuntingYard s(str);
    cout << s.evaluate() << "\n";
    return 0;
}