//
// Created by lidor on 19/12/18.
//

#include "LexerParser.h"

using namespace std;

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
        if(temp == "while" || temp == "if"){
            ConditionParser(lexer);
        }


        else if (mapStringCommand->isLeagalCommand(temp)) {
            cout << "the command is: " + temp << endl;
            lexer.pop_back();
            mapStringCommand->getCommand(temp)->doCommand
                    (lexer, _data);
        } else {
            cout << "Other : " + temp << endl;
            if (_data->isLeagalVar(temp)) {
                VarCommand *varCommand = new VarCommand();
                varCommand->doCommand(lexer, _data);
            } else {
                throw ("var is not valid!");
            }
        }
    }
}

void LexerParser::ReadFromFile(string fileName) {
    fstream file;
    file.open(fileName,
              std::fstream::in | std::fstream::out);
    ifstream infile(fileName);
    string line;
    while (getline(infile, line)) {
        LexerS(line);
    }
}

void LexerParser::ConditionParser(vector<string> &lexer) {
    // save the condition (if or while) and pop it
    string condition = lexer.back();
     lexer.pop_back();

     /**
      * now we bulid the condition after we know if its while or if
      */

    std::regex e("==|\\>|\\<|\\<=|\\>=|\\");

}