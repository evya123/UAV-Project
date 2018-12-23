//
// Created by lidor115 on 12/23/18.
//

#ifndef UAV_PROJECT_UTILS_H
#define UAV_PROJECT_UTILS_H

#include <string>
#include <regex>
#include "Expression/ShuntingYard.h"
#include "Maps/Data.h"

using namespace std;

bool isMathExpression(string s);
double dijkstra(string s);
double calculateExpression(string str, Data * d);

#endif //UAV_PROJECT_UTILS_H
