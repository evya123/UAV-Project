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
#include <Commends/PullAndPush/TcpServer.h>
#include "Commends/PrintCommand.h"
#include "Commends/ConnectCommand.h"
#include "Commends/SleepCommand.h"
#include "Commends/VarCommand.h"
#include "Commends/IfCommand.h"
#include "Commends/WhileCommand.h"
#include "Commends/EntercCommand.h"
#define INTEGER "i"
#define DOUBLE "d"
#define LHS 0
#define COMPARE 1
#define RHS 2
#define BRACKET_POS 3
#define BRACKET "{"
#define CLOSING_BRACKET "}"
#define IF_DELIMITER ";"

using namespace std;

class Utils {
public:
    static bool isMathExpression(string s);
    static double dijkstra(string s);
    static double calculateExpression(string str, Data * d);
    static double fromStringToNum(string &str, const string &type);
    static vector<string> splitByDelimiter(vector<string>::iterator &it, const string delimiter);
    static bool checkCondition(vector<string> &arguments, Data *_data, stack<string> &bStack);

private:
    stack<string> m_brackets;
};

#endif //UAV_PROJECT_UTILS_H
