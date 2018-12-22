//
// Created by lidor115 on 12/20/18.
//
#include <vector>
#include <map>
#include <regex>
#include <iostream>
#include <string>
#include <list>
#include "Maps/Data.h"
#include "Maps/MapStringCommand.h"
#include "Commends/Command.h"
#include "Expression/ShuntingYard.h"

using namespace std;

#ifndef UAV_PROJECT_LEXER_H
#define UAV_PROJECT_LEXER_H

class LexerParser {
private:
    Data *_data;
public:
    LexerParser(Data* data);
    void LexerS(string line);

    void checkRegex(list<string> &expretions, vector<string> &result, regex e);


    void FinalLexer(vector<string> &result, vector<string> &final);

    void Parser(vector<string> &lexer);

    bool isMathExpression(string s);

    double dijkstra(string s);

    void varOperation(vector<string> &varVec);

    void test();
};

#endif //UAV_PROJECT_LEXER_H
