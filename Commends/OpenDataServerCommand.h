//
// Created by evya on 12/17/18.
//

#ifndef DEV_OPENDATASERVERCOMMAND_H
#define DEV_OPENDATASERVERCOMMAND_H


#include "Command.h"
#include <stdexcept>

class OpenDataServerCommand : public Command {

public:
    OpenDataServerCommand() = default;
<<<<<<< HEAD

    virtual void doCommand(string arguments);
=======
    virtual void doCommand(const string &arguments);
>>>>>>> 518c70b9f8171c8304414254b70fa0a9684f8db4

private:
    int openDataServer();

    int convertToInt(string port);

    string m_args;
};


#endif //DEV_OPENDATASERVERCOMMAND_H
