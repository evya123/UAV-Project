//
// Created by evya on 12/25/18.
//

#ifndef UAV_PROJECT_ENTERCCOMMAND_H
#define UAV_PROJECT_ENTERCCOMMAND_H

#include "Commends/Command.h"
#include <stdio.h>

class EntercCommand : public Command{
    virtual void doCommand(vector<string> &arguments, Data *d);
};


#endif //UAV_PROJECT_ENTERCCOMMAND_H
