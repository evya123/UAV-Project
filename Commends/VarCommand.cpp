//
// Created by evya on 12/21/18.
//

#include "VarCommand.h"

void VarCommand::doCommand(const string &arguments) {
    string key = arguments.back();
    // if there is no var - build new var
    if (!_data->isLeagalVar(key)) {
        _data->addVar(key, 0);
    }
    while (arguments.back() != "=") {
        arguments.pop_back();
    }
    // pop the "="
    arguments.pop_back();
    /*
     * bind case
     */
    if (arguments.back() == "bind") {
        arguments.pop_back();
        // check if there is a legal bind
        string path = arguments.back();
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
    else if (isMathExpression(arguments.back())) {
        double value = dijkstra(arguments.back());
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
        string str = arguments.back();
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
                if (_data->isLeagalVar(var)) {
                    dString += to_string(_data->getVarValue(var));
                } else {
                    throw ("illegal Expression");
                }
            } else {
                dString += var;
            }
            dString += op;
        }
        double value = dijkstra(dString);
        _data->assignVar(key, value);
        if (_data->isBind(key)) {
            _data->changeBindValue(_data->getPath(key), value);
        }

    }
    arguments.pop_back();
}
