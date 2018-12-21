//
// Created by evya on 12/14/18.
//

#include <stdio.h>
#include "Expression/ShuntingYard.h"
#include <string>
#include <iostream>
#include "Commends/PrintCommand.h"


int main() {
PrintCommand* p = new PrintCommand();
p->doCommand("this is a test");

return 0;
}
