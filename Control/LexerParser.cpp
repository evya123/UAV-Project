//
// Created by lidor on 19/12/18.
//

#include "LexerParser.h"

using namespace std;


void checkRegex(list<string> &expretions, vector<string> &result, regex e);


void LexerS(string line) {
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
    std::regex e("=|\\+|\\*|\\(|\\)|\\-|\\,|\\<|\\>|\\/|\\&|\\||\\!");

    checkRegex(expretions, result, e);
    vector<string> final;
    FinalLexer(result, final);
    Parser(final);
}

void checkRegex(list<string> &expretions, vector<string> &result, regex e) {
    std::smatch m;
    // for each expresion divided by space
    for (list<string>::iterator word = expretions.begin(); word != expretions
            .end(); ++word) {
        if (!(result.empty())) {
            string c = word->substr(0, 1);
            string back = result.back();
            // if there is "=" or there was "=" before put "," if there
            // wasn't operation and now its not an operation
            if (!(regex_match(result.back(), e)) && !(regex_match(c, e))) {
                result.push_back(",");
            }
        }

        while (std::regex_search(*word, m, e)) {
            // push the prefix
            if (m.prefix() != "") {
                result.push_back(m.prefix().str());
            }
            // push the operation
            string op;
            for (auto x:m) {
                op = x;
            }
            if ((regex_match(result.back(), regex("="))) ||
                (regex_match(op, regex("=")))) {
                result.push_back(",");
            }
            result.push_back(op);
            *word = m.suffix().str();
        }
        if (!result.empty() && (regex_match(result.back(), regex("=")))) {
            result.push_back(",");
        }

        if (*word != "") {
            result.push_back(*word);
        }
    }
}


void FinalLexer(vector<string> &result, vector<string> &final) {
    string r;
    while (!result.empty()) {
        string temp = "";
        string check = result.back();
        while (result.back() != ",") {
            r = result.back() + r;
            result.pop_back();
            if (result.empty()) {
                break;
            }
        }
        if (!result.empty()) {
            result.pop_back();
        }
        if (r != "") {
            final.push_back(r);
        }
        r = "";
    }
}


void Parser(vector<string> &lexer) {
    Data *data = new Data();
    MapStringCommand *mapStringCommand = new MapStringCommand();
    string temp = "";

    while (!lexer.empty()) {
        // first if its a var - get the value
        temp = lexer.back();
        if (mapStringCommand->isLeagalCommand(temp)) {
            cout << "the command is: " + temp << endl;
        } else if (isMathExpression(temp)) {
            cout << "it's a math expression: " + temp << endl;
            string t = dijkstra(temp);
            cout << "after dijkstra: " + t << endl;

        }

        lexer.pop_back();
    }

}

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

string dijkstra(string s) {
    string newStr;
    std::smatch m1;
    std::smatch m2;
    std::regex e("[a-z]+|\\[A-Z]+");
    std::regex r("\\+|\\*|\\(|\\)|\\-|\\/");
    while (s != "") {
        if (regex_search(s, m1, r)) {
            newStr += m1.prefix();
            string op;
            for (auto x:m1) {
                op = x;
            }
            newStr += ' ';
            newStr += op;
            s = m1.suffix();
        } else {
            newStr += s;
            s = "";
        }
    }
    ShuntingYard shuntingYard(newStr);
    double temp = shuntingYard.evaluate();
    return to_string(temp);
}


void test() {
    string str = "var h0 = heading";
    LexerS(str);
    string str1 = "var breaks = bind /hhhs/ggg/ggg ";
    LexerS(str1);
    string str2 = "var x =3";
    LexerS(str2);

}

