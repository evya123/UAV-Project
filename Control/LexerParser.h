//
// Created by lidor115 on 12/20/18.
//



#ifndef UAV_PROJECT_LEXER_H
#define UAV_PROJECT_LEXER_H

#include <regex>
#include <string>
#include <list>
#include "Expression/ShuntingYard.h"
#include "Utils.h"
#include <fstream>
#include "ExpressionCommand.h"
#include <Commends/PullAndPush/TcpServer.h>
#include <algorithm>

class TcpServer;
using namespace std;
class LexerParser {
private:
    Data *_data;
    map<string, Command *> _mapStringCommad;
    string _content;
    bool condition_lock;
    vector<string> conditionVec;
    int brackets;
    bool isfirstbrackets;
public:
    explicit LexerParser(Data *data, TcpClient *client, TcpServer *server);

    void LexerS(string line);

    void checkRegex(list<string> &expretions, vector<string> &result, regex e);

    void FinalLexer(vector<string> &result, vector<string> &final);

    void Parser(vector<string> &lexer);

    void setMapStringCommand(TcpClient*, TcpServer*);

    void
    ConditionParser(vector<string> &lexer);

    void ReadFromFile(string fileName);

    void ExcecuteCommand(vector<string> &lexer, Command *);

    void setConditionLock(bool);

    void ConditionparserWhile(vector<string> &lexer);

    string Readline();

    bool isLeagalCommand(const string c) const;

    Command *getCommand(const string c) const;

    virtual ~LexerParser();
};

#endif //UAV_PROJECT_LEXER_H
