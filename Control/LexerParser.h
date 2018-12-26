//
// Created by lidor115 on 12/20/18.
//



#ifndef UAV_PROJECT_LEXER_H
#define UAV_PROJECT_LEXER_H

#include <regex>
#include <string>
#include <list>
#include "Maps/MapStringCommand.h"
#include "Expression/ShuntingYard.h"
#include "Utils.h"
#include <fstream>
#include "ExpressionCommand.h"
#include "Commends/IfCommand.h"
#include <algorithm>


using namespace std;

class LexerParser {
private:
    Data *_data;
    MapStringCommand *_mapStringCommad;
    unsigned long int _lineNumber;
    string _content;
    bool condition_lock;
    vector<string> conditionVec;
    int brackets;
    bool isfirstbrackets;
public:
    explicit LexerParser(Data *data, MapStringCommand *);

    void LexerS(string line);

    void checkRegex(list<string> &expretions, vector<string> &result, regex e);

    void FinalLexer(vector<string> &result, vector<string> &final);

    void Parser(vector<string> &lexer);

    vector<string>
    ConditionParser(vector<string> &lexer);

    void ReadFromFile(string fileName);

    void ExcecuteCommand(vector<string> &lexer, Command *);


    void ConditionparserWhile(vector<string> &lexer);

    string Readline();
};

#endif //UAV_PROJECT_LEXER_H
