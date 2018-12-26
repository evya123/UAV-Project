
#include "OpenDataServerCommand.h"
OpenDataServerCommand::OpenDataServerCommand(TcpServer *server) {
    m_server = server;
}

/**
 * Function name: convertToInt
 * @param port
 * @return return the Integer presentation of the string
 * Uses stoi as a black box. If exception occurred,
 * print the information about it and exit properly.
 */
int OpenDataServerCommand::convertToInt(string port) {
    try {
        return stoi(port);
    } catch(invalid_argument& e){
        // if no conversion could be performed
        printf("OpenDataServerCommand->convertToInt: %s", e.what());
        exit(EXIT_FAILURE);
    } catch(out_of_range& e){
        // if the converted value would fall out of the range of the result type
        // or if the underlying function (std::strtol or std::strtoull) sets errno
        // to ERANGE.
        printf("OpenDataServerCommand->convertToInt: %s", e.what());
        exit(EXIT_FAILURE);
    } catch(exception& e) {
        // everything else
        printf("OpenDataServerCommand->convertToInt: %s", e.what());
        exit(EXIT_FAILURE);
    }
}

void OpenDataServerCommand::doCommand(vector<string> &arguments, Data *d) {
    cout<<"OpenDataServerCommand!"<<endl;
    int port = convertToInt(arguments.back());
    arguments.clear();
    TcpStruct args;
    m_server->setup(port);
    args.arg1 = m_server->receive();
    args.arg2 = d;
    thread dataServer(TcpServer::TaskServer,&args);

    dataServer.detach();
}

OpenDataServerCommand::~OpenDataServerCommand() {
    delete m_server;
}



