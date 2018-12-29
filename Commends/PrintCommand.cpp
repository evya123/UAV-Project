//
// Created by evya on 12/21/18.
//

#include <vector>
#include <Utils.h>
#include "PrintCommand.h"

void PrintCommand::doCommand(vector<string> &arguments, Data *d) {
    std::size_t i;
    string finalPrint;
    bool quatation = false;
    string toprint;
    string check;
    int first_quatation;
    int last_quatation;
    while (!arguments.empty()) {
        toprint = arguments.back();
        arguments.pop_back();
        while (!toprint.empty()) {
            if (!quatation) {
                first_quatation = toprint.find_first_of("\"");
                // no first quatation!
                if (first_quatation == -1) {
                    printMath(toprint, d);
                    finalPrint += toprint + " ";
                    toprint = "";
                    continue;
                } // first quatation!
                else {
                    quatation = true;
                    check = toprint.substr(0, first_quatation);
                    printMath(check, d);
                    finalPrint += check + " ";
                    toprint = toprint.substr(first_quatation + 1,
                                             toprint.size());
                    continue;
                }
                // there was first quatation
            } else {
                last_quatation = toprint.find_first_of("\"");
                // there was last quatation!
                if (last_quatation != -1) {
                    finalPrint += toprint.substr(0, last_quatation) + " ";
                    quatation = false;
                    toprint = toprint.substr(last_quatation + 1,
                                             toprint.size());
                    continue;

                } // there was not last quatation
                else {
                    finalPrint += toprint + " ";
                    toprint = "";
                    continue;
                }
            }
        }
    }
    cout << finalPrint << endl;
}

void PrintCommand::printMath(string &str, Data *d) {
    if (str == "") {
        return;
    }
    try {
        double dob = Utils::calculateExpression(str, d);
        str = to_string(dob);
    } catch (exception &e) {
        throw "illegal Expression!";
    }
}

