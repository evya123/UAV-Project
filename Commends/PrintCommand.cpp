//
// Created by evya on 12/21/18.
//

#include <vector>
#include "PrintCommand.h"
void PrintCommand::doCommand(vector<string> &arguments, Data *d) {
    std::size_t i;
    for (i = arguments.size() - 1; i > 0; --i){
        std::cout << arguments[i]<<" ";
    }
    std::cout<<arguments[i]<<"\n";
    arguments.clear();
}
