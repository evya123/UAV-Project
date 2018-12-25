//
// Created by evya on 12/21/18.
//

#include "VarCommand.h"

void VarCommand::doCommand(vector<string> &arguments, Data *d) {
    string name = arguments.back();
    Var *var;
    // if there is no var - build new var
    if (!d->isLeagalVar(name)) {
        Var *v = new Var(name); //Var*
        var = v;
        d->addVar(name, var); // its ok - mutex at the var - the add is in
        // the Data - Don't worry
    } else {
        var = d->getVar(name);  //Var* - we don't change the var here
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
        RemoveQuotationMark(path);
        if (d->isPath(path)) {
            d->addPathAndVar(var, path); // Map - var path
        }
            // its somthing like var x = bind y
        else if (d->isLeagalVar(path)) {
            d->addPathAndVar(var, path); // Map - var path
            d->changeVarBind(var, path);// change the path of var in Data class
            d->changeVarValue(var, d->getVar(path)->getValue());
            //its not a variable but unknown path
        } else if (!d->isLeagalVar(path)) {
            d->changeVarBind(var, path);// change the path of var in Data class
            d->setPath(path, var->getValue()); // Map - var-Path
            d->addBind(var, path);             // Map -var - path
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
        d->assignVar(name, value);   // all maps
    }
    arguments.

            pop_back();
}


void VarCommand::RemoveQuotationMark(string &path) {
    path.erase(remove(path.begin(), path.end(), '\"'), path.end());
    path.erase(path.begin());
}
