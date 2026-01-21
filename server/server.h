#ifndef SERVER_H
#define SERVER_H

#include <vector>
#include <thread>
#include <string>

class Server {
public:
    Server(int port);
    void start();

private:
    int serverSocket;
    std::vector<int> clients;

    void acceptClients();
    void handleClient(int clientSocket);
    void broadcast(const std::string& message);
};

#endif
