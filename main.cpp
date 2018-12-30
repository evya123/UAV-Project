
#include "Control/LexerParser.h"

bool exit(string &str, TcpClient *client, TcpServer *server) {

    if (!str.compare("exit")) {
        server->detach();
        client->exit();
        return true;
    }
    return false;
}


void startUI(int argc, char *argv[]) {
    TcpClient *client = new TcpClient();
    Data *data = new Data(client);
    TcpServer *server = new TcpServer();
    LexerParser *lexerParser = new LexerParser(data, client, server);
    string str = " ";
    bool firstTime = true;
    if (argc < 2) {
        while (true) {
            if (firstTime) {
                cout << "**FlightGear by Lidor and Evyatar**\n"
                        "Please type your command: >>" << endl;
                firstTime = false;
            }
            cout << ">> ";
            if (exit(str, client, server)) {
                cout << "Exiting Flight Gear, see you later!" << endl;
                break;
            }
            getline(cin, str);
            lexerParser->LexerS(str);
        }

    } else {
        lexerParser->ReadFromFile(argv[1]);
    }
    delete server;
    delete client;
    delete data;
    delete lexerParser;
}

int main(int argc, char *argv[]) {
    startUI(argc, argv);
    return 0;
}