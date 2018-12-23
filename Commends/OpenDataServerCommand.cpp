
#include "OpenDataServerCommand.h"
OpenDataServerCommand::OpenDataServerCommand() {
    m_server = new TcpServer();
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

int OpenDataServerCommand::openDataServer(int port) {
    m_server->setup(port);
    //m_server->receive();

}

void OpenDataServerCommand::doCommand(vector<string> &arguments, Data *d) {
    int port = convertToInt(arguments[PORT_POS]);
    m_server->setup(port);
    m_server->receive();
}

OpenDataServerCommand::~OpenDataServerCommand() {
    delete m_server;
}
