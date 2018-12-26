//
// Created by lidor115 on 12/23/18.
//

#ifndef UAV_PROJECT_UTILS_H
#define UAV_PROJECT_UTILS_H

#include <string>
#include <regex>
#include "Expression/ShuntingYard.h"
#include "Maps/Data.h"
#define INTEGER "i"
#define DOUBLE "d"

using namespace std;

class Utils {
public:
    static bool isMathExpression(string s);
    static double dijkstra(string s);
    static double calculateExpression(string str, Data * d);
    static double fromStringToNum(string &str, const string &type);
};

#endif //UAV_PROJECT_UTILS_H
