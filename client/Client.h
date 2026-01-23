#ifndef CLIENT_H
#define CLIENT_H

#include "socket_utils.h"
#include <string>

class Client {
private:
    socket_t socketFd;
    std::string serverIp;
    int serverPort;
    std::string pseudo;

public:
    Client(const std::string& ip, int port);
    bool connectToServer();
    void sendMessage(const std::string& message);
    void listen(); // boucle pour recevoir les messages
};

#endif
