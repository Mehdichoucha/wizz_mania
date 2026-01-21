#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
public:
    Client(const std::string& ip, int port);
    void connectToServer();
    void sendMessage(const std::string& message);
    void listen();

private:
    int socketFd;
    std::string serverIp;
    int serverPort;
};

#endif
