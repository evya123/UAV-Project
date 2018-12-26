//
// Created by evya on 12/25/18.
//

#include "EntercCommand.h"

void EntercCommand::doCommand(vector<string> &arguments, Data *d) {
    cout << "Press ENTER to continue...";
    cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
}
