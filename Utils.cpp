//
// Created by lidor115 on 12/23/18.
//

#include "Utils.h"


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

double calculateExpression(string str, Data *d) {
    string dString;
    smatch m;
    std::regex r("\\+|\\*|\\(|\\)|\\-|\\/|\\(|\\)");
    while (str != "") {
        regex_search(str, m, r);
        string op;
        for (auto x:m) {
            op = x;
        }
        string var = m.prefix();
        if (op == "") {
            var = str;
        }
        str = m.suffix();
        if (!isMathExpression(var)) {
            if (d->isLeagalVar(var)) {
                dString += to_string(d->getVarValue(var));
            } else {
                throw ("illegal Expression");
            }
        } else {
            dString += var;
        }
        dString += op;
    }
    double value = dijkstra(dString);

    return value;
}