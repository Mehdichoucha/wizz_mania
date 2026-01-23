#ifndef SERVER_H
#define SERVER_H

#include <vector>
#include <thread>
#include <string>
#include "socket_utils.h"

class Server {
public:
    Server(int port);
    void start();

private:
    socket_t serverSocket;          // 👈 socket du serveur
    std::vector<socket_t> clients;  // 👈 sockets clients
    int port;

    void acceptClients();
    void handleClient(socket_t clientSocket);
    void broadcast(const std::string& message);
};

#endif
