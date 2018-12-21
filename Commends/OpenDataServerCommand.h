//
// Created by evya on 12/17/18.
//

#ifndef DEV_OPENDATASERVERCOMMAND_H
#define DEV_OPENDATASERVERCOMMAND_H


#include "Command.h"
#include <stdexcept>

class OpenDataServerCommand : public Command{

public:
    OpenDataServerCommand() = default;
    virtual void doCommand(const string &arguments);

private:
    int openDataServer();
    int convertToInt(string port);

    string m_args;
};


#endif //DEV_OPENDATASERVERCOMMAND_H
