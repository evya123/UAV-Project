
#include "OpenDataServerCommand.h"
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


int OpenDataServerCommand::openDataServer() {



}

void OpenDataServerCommand::doCommand(const string &arguments) {
    //TODO: create thread and add the function to the thread

}