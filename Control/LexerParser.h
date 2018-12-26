//
// Created by lidor115 on 12/20/18.
//



#ifndef UAV_PROJECT_LEXER_H
#define UAV_PROJECT_LEXER_H
#include <regex>
#include <string>
#include <list>
#include "Maps/MapStringCommand.h"
<<<<<<< HEAD
=======
#include "Expression/ShuntingYard.h"
>>>>>>> 9e9d907a7412a70e123a178c5f7668327171fe57
#include "Utils.h"
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
