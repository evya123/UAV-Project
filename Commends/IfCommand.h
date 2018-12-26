//
// Created by evya on 12/21/18.
//

#ifndef UAV_PROJECT_IFCOMMAND_H
#define UAV_PROJECT_IFCOMMAND_H

#include "Command.h"
#include "Commends/ConditionCommand.h"
#include "ArithmeticConditions.h"
<<<<<<< HEAD
#include "Control/LexerParser.h"
=======
>>>>>>> 50ccfc62480e0d460ea8805b27593848482a0288

#define LHS 0
#define COMPARE 1
#define RHS 2

class IfCommand : public ConditionCommmand {
public:
    IfCommand();
<<<<<<< HEAD

=======
>>>>>>> 50ccfc62480e0d460ea8805b27593848482a0288
    virtual void doCommand(vector<string> &arguments, Data *d);

private:
    vector<string>
    splitByDelimiter(vector<string>::iterator &, const string delimiter);

    ArithmeticConditions m_ac;
<<<<<<< HEAD
    MapStringCommand *m_msc;
=======
>>>>>>> 50ccfc62480e0d460ea8805b27593848482a0288
};


#endif //UAV_PROJECT_IFCOMMAND_H
