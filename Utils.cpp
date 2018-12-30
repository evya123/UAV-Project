//
// Created by lidor115 on 12/23/18.
//

#include "Utils.h"

/**
 * check if the expression is a math expression
 * @param s string of expression
 * @return if its math expression or not
 */
bool Utils::isMathExpression(string s) {
    std::regex e("[a-z]+|\\[A-Z]+");
    std::smatch m;
    string match;
    if (regex_search(s, m, e)) {
        return false;
    } else {
        return true;
    }
}

/**
 * prepare the var to shuanting yard algorithm.
 * @param s string of an expression
 * @return the value in double after shuanting yard
 */
double Utils::dijkstra(string s) {
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
            // making spaces - prepare for dijkstra
            newStr += ' ';
            newStr += op;
            newStr += ' ';
            s = m1.suffix();
        } else {
            newStr += s;
            s = "";
        }
    }
    // shuntingyard
    ShuntingYard shuntingYard(newStr);
    double temp = shuntingYard.evaluate();
    return temp;
}

/**
 * input: math expression, and the output is double (the value)
 * @param str
 * @param d
 * @return
 */
double Utils::calculateExpression(string str, Data *d) {
    string dString;
    smatch m;
    // find the operations
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
        // the string now is only the suffix
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
    // sending to dijkstra and return the value.
    double value = dijkstra(dString);

    return value;
}

/**
 * get string and type and return double
 * @param str string of expression
 * @param type type of the expression
 * @return the value of the expression
 */
double Utils::fromStringToNum(string &str, const string &type) {
    try {
        if (type.compare(INTEGER) == 0)
            return stoi(str);
        if (type.compare(DOUBLE) == 0)
            return stod(str);
    } catch (invalid_argument &e) {
        // if no conversion could be performed
        printf("OpenDataServerCommand->fromStringToNum: %s", e.what());
        exit(EXIT_FAILURE);
    } catch (out_of_range &e) {
        // if the converted value w/ould fall out of the range of the result type
        // or if the underlying function (std::strtol or std::strtoull) sets errno
        // to ERANGE.
        printf("OpenDataServerCommand->fromStringToNum: %s", e.what());
        exit(EXIT_FAILURE);
    } catch (exception &e) {
        // everything else
        printf("OpenDataServerCommand->fromStringToNum: %s", e.what());
        exit(EXIT_FAILURE);
    }
    return 0;
}

/**
 *
 * @param it iterator of the vector
 * @param delimiter - ";"
 * @return the vector split by delimiter
 */
vector<string> Utils::splitByDelimiter(vector<string>::iterator &it,
                                       const string delimiter) {
    vector<string> ret;
    if (!(*it).empty()) {
        while ((*it).compare(delimiter) != 0 &&
               !(*it).empty()) {
            if ((*it).compare(SEMICOLON) == 0) {
                ++it;
                continue;
            }
        }
        if ((*it).compare(SEMICOLON) == 0)
            ++it;
        return ret;
    }
}

/**
 * get condintion and return if the condition is true or false.
 * @param arguments  - vector of arguments (first arg, condition, second arg)
 * @param _data  the data
 * @param bQueue stack
 * @return true if the condition is true and false otherwise
 */
bool Utils::checkCondition(vector<string> &arguments, Data *_data) {

    // now we
    // get 4 args - like x > 3 {
    //first argument
    string first_expression = arguments[LHS];
    // the condition
    string condition = arguments[COMPARE];
    // second argument
    string second_expression = arguments[RHS];
    // now we nee to have in args only {
    ArithmeticConditions *arithmeticConditions = new ArithmeticConditions();
    double first = Utils::calculateExpression(first_expression, _data);
    double second = Utils::calculateExpression(second_expression, _data);
    //return if the condition is true or false
    bool result = arithmeticConditions->getCondition(condition)(first, second);
    delete (arithmeticConditions);
    return result;

}

void Utils::clearQ(std::queue<vector<string>> &q) {
    std::queue<vector<string>> empty;
    std::swap(q, empty);
}

void Utils::ifRecursion(queue<vector<string>> &commands,
                        queue<vector<string>> &conditions,
                        Data *d, LexerParser *lp) {
    int killCounter = 1;
    if (conditions.empty() && commands.empty())
        return;
    vector<string> commandVec = commands.front();
    commands.pop();
    if (commandVec.front().compare(BRACKET) == 0) {
        vector<string> conditionCheck = conditions.front();
        conditions.pop();
        if (Utils::checkCondition(conditionCheck, d)) {
            conditions.push(conditionCheck);
            ifRecursion(commands, conditions, d, lp);
        } else {
            while (killCounter) {
                commandVec = commands.front();
                commands.pop();
                if (commandVec.front().compare(BRACKET) == 0) {
                    conditions.pop();
                    ++killCounter;
                } else if (commandVec.front().compare(CLOSING_BRACKET) == 0) {
                    conditions.pop();
                    --killCounter;
                }
            }
        }
        ifRecursion(commands, conditions, d, lp);
    } else {
        if (commandVec.front().compare(CLOSING_BRACKET) == 0) {
            if (!conditions.empty()) {
                conditions.pop();
                ifRecursion(commands, conditions, d, lp);
            }
        } else {
            reverse(commandVec.begin(), commandVec.end());
            lp->Parser(commandVec);
            ifRecursion(commands, conditions, d, lp);
        }
    }

}

void Utils::takeBetweenBrackets(queue<vector<string>> &commands,
                                queue<vector<string>> &conditions,
                                LexerParser *lp, Data *d) {

    queue<vector<string>> loopingVecCommands;
    queue<vector<string>> loopingVecConditions;
    vector<string> temp;
    vector<string> tempCondition;
    if (!commands.empty()) {
        int brackets = 0;
        bool firstB = false;
        while (brackets || !firstB) {
            temp = commands.front();
            loopingVecCommands.push(temp);
            if (temp.front().compare(BRACKET) == 0) {
                tempCondition = conditions.front();
                conditions.pop();
                conditions.push(tempCondition);
                loopingVecConditions.push(tempCondition);
                ++brackets;
                firstB = true;
            } else if (temp.front().compare(CLOSING_BRACKET) == 0) {
                --brackets;
                if (!brackets) {
                    break;
                }
            }
            commands.pop();
            commands.push(temp);
        }
    }
    commands = loopingVecCommands;
    conditions = loopingVecConditions;
}

void Utils::LoopCommand(queue<vector<string>> &commands,
                        queue<vector<string>> &conditions, Data *d,
                        LexerParser *lp) {
    vector<string> main_condition = conditions.front(); // condition
    vector<string> temp = commands.front(); // first bracket
    vector<string> parseVec; // condition
    vector<string> corrent_condition = conditions.front(); // condition

    commands.pop();
    commands.push(temp);

    while (checkCondition(main_condition, d)) {
        if (!checkCondition(corrent_condition, d)) {
            while (temp.front() != CLOSING_BRACKET) {
                temp = commands.front();
                commands.pop();
                commands.push(temp);
            }
            conditions.pop();
            conditions.push(corrent_condition);
            corrent_condition = conditions.front();
        }
        while (checkCondition(corrent_condition, d)) {
            temp = commands.front();
            commands.pop();
            commands.push(temp);

            if (temp.front() == BRACKET) {
                conditions.pop();
                conditions.push(corrent_condition);
                corrent_condition = conditions.front();
                continue;
            }
            if (temp.front() == CLOSING_BRACKET) {
                if (corrent_condition.front() == IF_CHECK) {
                    break;
                } else {
                    commands.pop();
                    commands.push(temp);
                    continue;
                }
            }
            parseVec = temp;
            reverse(parseVec.begin(), parseVec.end());
            lp->Parser(parseVec);
        }
        if (main_condition.front() == IF_CHECK) {
            break;
        }
    }
}

void Utils::WhileRecursion(queue<vector<string>> &commands,
                           queue<vector<string>> &conditions, Data *d,
                           LexerParser *lp) {
    int killCounter = 1;
    if (conditions.empty() && commands.empty())
        return;
    vector<string> commandVec = commands.front();
    commands.pop();
    if (commandVec.front().compare(BRACKET) == 0) {
        vector<string> conditionCheck = conditions.front();
        conditions.pop();
        if (Utils::checkCondition(conditionCheck, d)) {
            conditions.push(conditionCheck);
            ifRecursion(commands, conditions, d, lp);
        } else {
            while (killCounter) {
                commandVec = commands.front();
                commands.pop();
                if (commandVec.front().compare(BRACKET) == 0) {
                    conditions.pop();
                    ++killCounter;
                } else if (commandVec.front().compare(CLOSING_BRACKET) ==
                           0) {
                    conditions.pop();
                    --killCounter;
                }
            }
        }
        ifRecursion(commands, conditions, d, lp);
    } else {
        if (commandVec.front().compare(CLOSING_BRACKET) == 0) {
            if (!conditions.empty()) {
                conditions.pop();
                ifRecursion(commands, conditions, d, lp);
            }
        } else {
            reverse(commandVec.begin(), commandVec.end());
            lp->Parser(commandVec);
            ifRecursion(commands, conditions, d, lp);
        }
    }
}