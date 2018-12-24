//
// Created by evya on 12/14/18.
//

#include <stdio.h>
#include <Commends/OpenDataServerCommand.h>
#include <Commends/ConnectCommand.h>
#include <Control/LexerParser.h>

int main(int argc, char* argv[]) {
    Data* data = new Data();
    LexerParser* lp = new LexerParser(data);
    lp->ReadFromFile(argv[1]);
return 0;
}
