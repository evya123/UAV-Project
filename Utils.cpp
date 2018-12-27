//
// Created by lidor115 on 12/23/18.
//

#include "Utils.h"


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

double Utils::calculateExpression(string str, Data *d) {
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

double Utils::fromStringToNum(string &str, const string &type) {
    try {
        if(type.compare(INTEGER) == 0)
            return stoi(str);
        if(type.compare(DOUBLE) == 0)
            return stod(str);
    } catch(invalid_argument& e){
        // if no conversion could be performed
        printf("OpenDataServerCommand->fromStringToNum: %s", e.what());
        exit(EXIT_FAILURE);
    } catch(out_of_range& e){
        // if the converted value w/ould fall out of the range of the result type
        // or if the underlying function (std::strtol or std::strtoull) sets errno
        // to ERANGE.
        printf("OpenDataServerCommand->fromStringToNum: %s", e.what());
        exit(EXIT_FAILURE);
    } catch(exception& e) {
        // everything else
        printf("OpenDataServerCommand->fromStringToNum: %s", e.what());
        exit(EXIT_FAILURE);
    }
    return 0;
}


vector<string> Utils::splitByDelimiter(vector<string>::iterator &it,
                                          const string delimiter) {
    vector<string> ret;
    while ((*it).compare(delimiter) != 0 &&
            !(*it).empty()) {
        if((*it).compare(IF_DELIMITER) == 0){
            ++it;
            continue;
        }
        if((*it).compare(CLOSING_BRACKET) == 0)
            break;
        ret.push_back(*it);
        ++it;
    }
    if((*it).compare(IF_DELIMITER) == 0)
        ++it;
    return ret;
}

bool Utils::checkCondition(vector<string> &arguments, Data *_data, stack<string> &bStack) {

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
    return arithmeticConditions->getCondition(condition)(first, second);

}