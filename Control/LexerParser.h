//
// Created by lidor115 on 12/20/18.
//



#ifndef UAV_PROJECT_LEXER_H
#define UAV_PROJECT_LEXER_H
#include <vector>
#include <map>
#include <regex>
#include <iostream>
#include <string>
#include <list>
#include "Maps/MapStringCommand.h"
#include "Expression/ShuntingYard.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include "ExpressionCommand.h"
#include "Commends/IfCommand.h"


using namespace std;

class LexerParser {
private:
    Data *_data;
    MapStringCommand* _mapStringCommad;
public:
    explicit LexerParser(Data *data, MapStringCommand *);

    void LexerS(string line);

    void checkRegex(list<string> &expretions, vector<string> &result, regex e);

    void FinalLexer(vector<string> &result, vector<string> &final);

    void Parser(vector<string> &lexer);

    void ConditionParser(vector<string> &lexer);

    void ReadFromFile(string fileName);
};

#endif //UAV_PROJECT_LEXER_H
