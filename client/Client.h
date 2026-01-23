#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "socket_utils.h"

class Client {
public:
    Client(const std::string& ip, int port);
    bool connectToServer();
    void sendMessage(const std::string& message);
    void listen();

private:
    socket_t socketFd;   // 👈 le socket appartient au client
    std::string serverIp;
    int serverPort;
};

#endif
