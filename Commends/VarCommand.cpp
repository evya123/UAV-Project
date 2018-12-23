//
// Created by evya on 12/21/18.
//

#include "VarCommand.h"

void VarCommand::doCommand(vector<string> &arguments, Data *d) {
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
    /**
     * case 1 - var we have to bind
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
 * case 2 - vars we need to calculate or just a calculate
 */
    else {
        // string for dijecstra
        string str = arguments.back();
        double value = calculateExpression(str, d);
        d->assignVar(key, value);
        if (d->isBind(key)) {
            d->changeBindValue(d->getPath(key), value);
        }
    }
    arguments.pop_back();
}