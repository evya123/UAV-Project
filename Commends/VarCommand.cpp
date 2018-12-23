//
// Created by evya on 12/21/18.
//

#include "VarCommand.h"

void VarCommand::doCommand(vector <string> &arguments, Data *d) {
    string key = arguments.back();
    // if there is no var - build new var
    if (!d->isLeagalVar(key)) {
        d->addVar(key, 0);
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
        if (d->isPath(path)) {
            d->addPathAndVar(key, path);
            d->changeBindValue(path, d->getVarValue(key));
        } else {
            throw ("path %s is not valid", path);
        }
    }
        /**
         * case 2 - set value to a var
         */
    else if (isMathExpression(arguments.back())) {
        double value = dijkstra(arguments.back());
        d->assignVar(key, value);
        if (d->isBind(key)) {
            d->changeBindValue(d->getPath(key), value);
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
        d->assignVar(key, value);
        if (d->isBind(key)) {
            d->changeBindValue(d->getPath(key), value);
        }

    }
    arguments.pop_back();
}