//
// Created by lidor115 on 12/23/18.
//

#ifndef UAV_PROJECT_UTILS_H
#define UAV_PROJECT_UTILS_H

#include <regex>
#include "Expression/ShuntingYard.h"
#include "Maps/Data.h"
#include "Commends/ArithmeticConditions.h"
#include "Commends/OpenDataServerCommand.h"
#include "Commends/PrintCommand.h"
#include "Commends/ConnectCommand.h"
#include "Commends/SleepCommand.h"
#include "Commends/VarCommand.h"
#include "Commends/IfCommand.h"
#include "Commends/WhileCommand.h"
#include "Commends/EntercCommand.h"

#define INTEGER "i"
#define DOUBLE "d"
#define LHS 1
#define COMPARE 2
#define RHS 3
#define BRACKET "{"
#define CLOSING_BRACKET "}"
#define SEMICOLON ";"
#define IF_CHECK "if"
#define WHILE_CHECK "while"

using namespace std;

class LexerParser;

class Utils {
public:
    static bool isMathExpression(string s);

    static double dijkstra(string s);

    static double calculateExpression(string str, Data *d);

    static double fromStringToNum(string &str, const string &type);

    static vector<string>
    splitByDelimiter(vector<string>::iterator &it, const string delimiter);

    static bool checkCondition(vector<string> &arguments, Data *_data);

    static void clearQ(std::queue<vector<string>> &q);

    static void
    ifRecursion(queue<vector<string>> &commands,
                queue<vector<string>> &conditions,
                Data *d, LexerParser *lp);

    static void takeBetweenBrackets(queue<vector<string>> &commands,
                                       queue<vector<string>> &conditions,
                                       LexerParser *lp, Data *d);

    static void WhileRecursion(queue<vector<string>> &commands,
                               queue<vector<string>> &conditions,
                               Data *d, LexerParser *lp);

    static void
    LoopCommand(queue<vector<string>> &commands,
                queue<vector<string>> &conditions,
                Data *d, LexerParser *lp);
private:

};

#endif //UAV_PROJECT_UTILS_H
