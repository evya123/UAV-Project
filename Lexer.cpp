//
// Created by lidor on 19/12/18.
//

#include "Lexer.h"

using namespace std;


void checkRegex(list<string> &expretions, vector<string> &result, regex e);


vector<string> LexerS(string line) {
    list<string> expretions;
    vector<string> result;
    line = line + " ";
    while (line != "") {
        unsigned long firstSpace = line.find_first_of(' ');
        unsigned long endOfstring = line.size() - firstSpace - 1;
        string exp = line.substr(0, firstSpace);
        expretions.push_back(exp);
        line = line.substr(firstSpace + 1, endOfstring);
    }
    std::regex e("=|\\+|\\*|\\(|\\)|\\-|\\,|\\<|\\>|\\&|\\||\\!");

    checkRegex(expretions, result, e);
    return result;
}

void checkRegex(list<string> &expretions, vector<string> &result, regex e) {
    std::smatch m;
    // for each expresion divided by space
    for (list<string>::iterator word = expretions.begin(); word != expretions
            .end(); ++word) {
        while (std::regex_search(*word, m, e)) {
            if (m.prefix() != "") {
                result.push_back(m.prefix().str());
            }
            for (auto x:m) {
                result.push_back(x);
            }
            string check = m.prefix().str();
            *word = m.suffix().str();
        }
        if (*word != "") {
            result.push_back(*word);
        }
    }
}

