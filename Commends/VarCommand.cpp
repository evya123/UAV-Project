//
// Created by evya on 12/21/18.
//

#include "VarCommand.h"

void VarCommand::doCommand(vector<string> &arguments, Data *d) {
    string name = arguments.back();
    Var *var;
    // if there is no var - build new var
    if (!d->isLeagalVar(name)) {
        Var *v = new Var(name);
        var = v;
        d->addVar(name, var);
    } else {
        var = d->getVar(name);
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
            d->addPathAndVar(var, path);
        }
            // its somthing like var x = bind y
        else if (d->isLeagalVar(path)) {
            d->addPathAndVar(var, path);
            var->setBind(path);
            var->assign(d->getVar(path)->getValue());
            //its not a variable but unknown path
        } else if (!d->isLeagalVar(path)) {
            d->addPath(path);
            var->setBind(path);
            d->setPath(path, var->getValue());
        } else {
            throw ("Unsupported Operation!");
        }
    }
/**
 * case 2 - vars we need to calculate or just a calculate
 */
    else {
// string for dijecstra
        string str = arguments.back();
        double value = calculateExpression(str, d);
        d->
                assignVar(name, value
        );
    }
    arguments.

            pop_back();
}