//
// Created by lidor on 19/12/18.
//

#include "LexerParser.h"

using namespace std;


void checkRegex(list<string> &expretions, vector<string> &result, regex e);

LexerParser::LexerParser(Data *data) {
    _data = data;
}

void LexerParser::LexerS(string line) {
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

void LexerParser::checkRegex(list<string> &expretions, vector<string> &result,
                             regex e) {
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
                (regex_match(op, regex("="))) || (result.back() == "bind")) {
                result.push_back(",");
            }
            result.push_back(op);
            *word = m.suffix().str();
            if (regex_match(result.back(), regex("\\)")) && (!regex_match
                    (word->substr(0, 1), regex("\\+|\\-|\\*|\\/")))) {
                result.push_back(",");
            }


            if (!result.empty() && (regex_match(result.back(), regex("=")))) {
                result.push_back(",");
            }
        }
        if (*word != "") {
            result.push_back(*word);
        }
    }
}


void LexerParser::FinalLexer(vector<string> &result, vector<string> &final) {
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


void LexerParser::Parser(vector<string> &lexer) {
    MapStringCommand *mapStringCommand = new MapStringCommand();
    string temp = "";

    while (!lexer.empty()) {
        // first if its a var - get the value
        temp = lexer.back();
        if (temp == "var") {
            lexer.pop_back();
            varOperation(lexer);
            if (lexer.empty()) {
                break;
            }
            throw ("var is not valid");
        }
        if (mapStringCommand->isLeagalCommand(temp)) {
            cout << "the command is: " + temp << endl;
        } else if (isMathExpression(temp)) {
            cout << "it's a math expression: " + temp << endl;
            string t = to_string(dijkstra(temp));
            cout << "after dijkstra: " + t << endl;

        }
        lexer.pop_back();
    }

}

bool LexerParser::isMathExpression(string s) {
    std::regex e("[a-z]+|\\[A-Z]+");
    std::smatch m;
    string match;
    if (regex_search(s, m, e)) {
        return false;
    } else {
        return true;
    }
}

double LexerParser::dijkstra(string s) {
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

void LexerParser::varOperation(vector<string> &varVec) {
    string key = varVec.back();
    // if there is no var - build new var
    if (!_data->isLeagalVar(key)) {
        _data->addVar(key, 0);
    }
    while (varVec.back() != "=") {
        varVec.pop_back();
    }
    // pop the "="
    varVec.pop_back();
    /*
     * bind case
     */
    if (varVec.back() == "bind") {
        varVec.pop_back();
        // check if there is a legal bind
        string path = varVec.back();
        if (_data->isPath(path)) {
            _data->addPathAndVar(key, path);
            _data->changeBindValue(path, _data->getVarValue(key));
        } else {
            throw ("path %s is not valid", path);
        }
    }
        /**
         * case 2 - set value to a var
         */
    else if (isMathExpression(varVec.back())) {
        double value = dijkstra(varVec.back());
        _data->assignVar(key, value);
        if (_data->isBind(key)) {
            _data->changeBindValue(_data->getPath(key), value);
        }
    }
        /**
         * case 3 - vars we need to calculate
         */
    else {
        // string for dijecstra
        string dString;
        string str = varVec.back();
        smatch m;
        std::regex r("\\+|\\*|\\(|\\)|\\-|\\/|\\(|\\)");
        while (str != "") {
            regex_search(str, m, r);
            string op;
            for (auto x:m) {
                op = x;
            }
            string var = m.prefix();
            str = m.suffix();
            if (!isMathExpression(var)) {
                if (_data->isLeagalVar(var)) {
                    dString += to_string(_data->getVarValue(var));
                } else {
                    throw ("illegal Expression");
                }
            } else {
                dString = m.suffix();
            }
            dString += op;
        }
        double num =dijkstra(dString);
    }
    varVec.pop_back();
}