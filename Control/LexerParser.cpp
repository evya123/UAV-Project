//
// Created by lidor on 19/12/18.
//

#include "LexerParser.h"

/**
 * constructor of the lexer-parser
 * @param data - the maps of the path and variables
 * @param client - client
 * @param server - server
 */
LexerParser::LexerParser(Data *data, TcpClient *client, TcpServer *server) {
    _data = data;
    // lock if there is a condition while or if commands
    condition_lock = false;
    // for conditions like if and while
    brackets = 0;
    isfirstbrackets = false;
    // set the map of the commands
    setMapStringCommand(client, server);
}

/**
 * get line and lex the line into
 * @param line line from the file/command line
 */
void LexerParser::LexerS(string line) {
    if (line == "" || line == " ") {
        return;
    }
    list<string> expretions;
    // split line by spaces
    vector<string> result;
    line = line + " ";
    while (line != "") {
        unsigned long firstSpace = line.find_first_of(' ');
        unsigned long endOfstring = line.size() - firstSpace - 1;
        string exp = line.substr(0, firstSpace);
        if (exp == "") {
            line = line.substr(firstSpace + 1, endOfstring);
            continue;
        }
        expretions.push_back(exp);
        line = line.substr(firstSpace + 1, endOfstring);
    }
    // set the regex
    std::regex e(
            ">=|\\<=|\\==|\\=>|\\=<|\\!=|\\=!|"
            "\\=|\\+|\\*|\\(|\\)|\\-|\\,|\\"
            "<|\\>|\\/|\\}|\\{|\\&|\\||\\!");

    checkRegex(expretions, result, e);
    vector<string> final;
    FinalLexer(result, final);
    Parser(final);
}

void LexerParser::checkRegex(list<string> &expretions, vector<string> &result,
                             regex e) {

    if (expretions.size() == 1) {
        string check_brackets = expretions.front();
        if (check_brackets == BRACKET || check_brackets == CLOSING_BRACKET) {
            result.push_back(check_brackets);
            expretions.clear();
            return;
        }
    }
    std::smatch m;
    // for each expresion divided by space
    for (list<string>::iterator word = expretions.begin(); word != expretions
            .end(); ++word) {
        if (*word == " " || *word == "") {
            continue;
        }

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
            // regex for boolean expressions, equal and brackets
            regex r(">=|\\<=|\\==|\\=>|\\=<|\\!=|\\=!|\\=|\\<|\\>|\\}|\\{");
            if (!result.empty()) {
                if ((regex_match(result.back(), r)) ||
                    (regex_match(op, r))
                    || (result.back() == "bind")) {
                    result.push_back(",");
                }
                result.push_back(op);
                *word = m.suffix().str();
                if (regex_match(result.back(), regex("\\)")) &&
                    (!regex_match(word->substr(0, 1),
                                  regex("\\+|\\-|\\*|\\/")))) {
                    result.push_back(",");
                }
            }

            if (!result.empty() && (regex_match(result.back(), r))) {
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
    string temp = "";
    while (!lexer.empty()) {
        // first if its a var - get the value
        temp = lexer.back();
        if (temp == "while" || temp == "if" || condition_lock) {
            if (condition_lock) {
                ConditionParser(lexer);
                return;
            }
            condition_lock = true;
            ConditionParser(lexer);
            Command *commander = getCommand(temp);
            ExcecuteCommand(conditionVec, commander);
            return;
        } else {
            if (isLeagalCommand(temp)) {
                lexer.pop_back();
                Command *command = getCommand(temp);
                ExcecuteCommand(lexer, command);
            } else {
                if (_data->isLeagalVar(temp)) {
                    ExcecuteCommand(lexer, _mapStringCommad["var"]);
                } else {
                    throw ("var is not valid!");
                }
            }
        }
    }
}


void LexerParser::ExcecuteCommand(vector<string> &lexer, Command *command) {
    ExpressionCommand *expressionCommand = new
            ExpressionCommand(command, &lexer, _data);
    expressionCommand->calculate();
    delete (expressionCommand);
}

void LexerParser::ReadFromFile(string filename) {
    fstream file;
    file.open(filename);
    ifstream _infile(filename);
    string line;
    int lineNumber = 0;
    while (getline(_infile, line)) {
        _content += line + " \n ";
        lineNumber++;
    }
    while (!_content.empty()) {
        LexerS(Readline());
    }
}


void LexerParser::ConditionParser(vector<string> &lexer) {
    // count the bracksets { = +1 , } = -1
    ConditionparserWhile(lexer);
    condition_lock = false;
}

string LexerParser::Readline() {
    int n = 0;
    string line = "";
    if (!_content.empty()) {
        n = _content.find_first_of("\n");
        if (n == -1) {
            _content.clear();
            return "";
        }
        line = _content.substr(0, n);
        _content.erase(0, n);
        if (!_content.empty()) {
            _content.erase(0, 1);
        }
    }
    return line;
}

void
LexerParser::ConditionparserWhile(vector<string> &lexer) {
    if (!isfirstbrackets || brackets > 0) {
        if (lexer.front() == "{") {
            ++brackets;
            isfirstbrackets = true;
        }
        if (lexer.front() == "}") {
            brackets -= 1;
        }
        try {
            while (!lexer.empty()) {
                conditionVec.push_back(lexer.back());
                lexer.pop_back();
            }
            conditionVec.push_back(";");
        } catch (exception e) {
            cout << e.what() << endl;
        }

        try {
            lexer.clear();
        } catch (exception e) {
            cout << e.what() << endl;
        }
        try {
            if (brackets > 0 || !isfirstbrackets) {
                LexerS(Readline());
            }
        } catch (exception e) {
            cout << e.what() << endl;

        }
    }
}


void
LexerParser::setMapStringCommand(TcpClient *client, TcpServer *server) {
    //OpenData server command
    Command *openDataServer = new OpenDataServerCommand(server);
    _mapStringCommad.insert(pair<string, Command *>("openDataServer",
                                                    openDataServer));
    //Print Command
    Command *printCommand = new PrintCommand();
    _mapStringCommad.insert(pair<string, Command *>("print",
                                                    printCommand));
    //Connect Command
    Command *connectCommand = new ConnectCommand(client);
    _mapStringCommad.insert(pair<string, Command *>("connect",
                                                    connectCommand));

    //VarCommand
    Command *varCommand = new VarCommand();
    _mapStringCommad.insert(pair<string, Command *>("var", varCommand));

    //ifComnand
    Command *ifCommand = new IfCommand(this);

    _mapStringCommad.insert(pair<string, Command *>("if", ifCommand));

    //whileCommand - its if command to...
    Command *whileCommand = new IfCommand(this);
    _mapStringCommad.insert(pair<string, Command *>("while", whileCommand));

    //Enterc
    Command *entercCommand = new EntercCommand();
    _mapStringCommad.insert(pair<string, Command *>("Enterc",
                                                    entercCommand));
    //Sleep
    Command *sleepCommand = new SleepCommand();
    _mapStringCommad.insert(pair<string, Command *>("sleep",
                                                    sleepCommand));
}


/**
 * get strign and return if the string represent a command or not.
 * @param c  - command (in string)
 * @return if the string represent a command or not
 */
bool LexerParser::isLeagalCommand(const string c) const {
    if (_mapStringCommad.count(c) > 0) {
        return true;
    }
    return false;
}

/**
 * get strign and return the command the string represent.
 * @param c  - command (in string)
 * @return the command the string represent if its illegal return nullptr
 */
Command *LexerParser::getCommand(const string c) const {
    return _mapStringCommad.at(c);

}

/**
 * Distructor,
 */
LexerParser::~LexerParser() {
    // check if the map isn't empty
    for (map<string, Command *>::iterator it = _mapStringCommad.begin();
         it != _mapStringCommad.end(); ++it) {
        //delete map and place null pointer;
        delete it->second;
    }
}

void LexerParser::setConditionLock(bool c) {
    condition_lock = c;
    isfirstbrackets = c;
}