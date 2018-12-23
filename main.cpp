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

int main(int argc, char* argv[]) {
    Data* data = new Data();
    LexerParser* l = new LexerParser(data);
    l->ReadFromFile(argv[1]);
return 0;
}
