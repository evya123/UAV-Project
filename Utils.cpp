//
// Created by lidor115 on 12/23/18.
//
#include <string>
#include <regex>
#include "Expression/ShuntingYard.h"
#include "Utils.h"
using namespace std;

bool isMathExpression(string s) {
    std::regex e("[a-z]+|\\[A-Z]+");
    std::smatch m;
    string match;
    if (regex_search(s, m, e)) {
        return false;
    } else {
        return true;
    }
}

double dijkstra(string s) {
    string newStr;
    std::smatch m1;
    std::smatch m2;
    std::regex e("[a-z]+|\\[A-Z]+");
    std::regex r("\\+|\\*|\\(|\\)|\\-|\\/|\\(|\\)");
    while (s != "") {
        if (regex_search(s, m1, r)) {
            newStr += m1.prefix();
            string op;
            for (auto x:m1) {
                op = x;
            }
            newStr += ' ';
            newStr += op;
            newStr += ' ';
            s = m1.suffix();
        } else {
            newStr += s;
            s = "";
        }
    }
    ShuntingYard shuntingYard(newStr);
    double temp = shuntingYard.evaluate();
    return temp;
}
