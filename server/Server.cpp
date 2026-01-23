#include "Server.h"
#include "socket_utils.h"
#include "protocol.h"
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <cstring>

Server::Server(int port) : port(port) {}

void Server::start() {
    // Création du socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        std::cerr << "Erreur création socket serveur\n";
        return;
    }

    // Adresse serveur
    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind
    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Erreur bind\n";
        closeSocket(serverSocket);
        return;
    }

    // Listen
    if (listen(serverSocket, 5) < 0) {
        std::cerr << "Erreur listen\n";
        closeSocket(serverSocket);
        return;
    }

    std::cout << "Serveur démarré sur le port " << port << "\n";

    // Accepter les clients dans ce thread
    acceptClients();
}

void Server::acceptClients() {
    while (true) {
        sockaddr_in clientAddr{};
#ifdef _WIN32
        int addrLen = sizeof(clientAddr);
#else
        socklen_t addrLen = sizeof(clientAddr);
#endif
        socket_t clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &addrLen);
        if (clientSocket < 0) {
            std::cerr << "Erreur accept\n";
            continue;
        }

        std::cout << "Nouveau client connecté\n";

        {
            std::lock_guard<std::mutex> lock(clientsMutex);
            clients.push_back(clientSocket);
        }

        // Lancer un thread pour gérer ce client
        std::thread(&Server::handleClient, this, clientSocket).detach();
    }
}

void Server::handleClient(socket_t clientSocket) {
    char buffer[1024];

    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived <= 0) break; // client déconnecté

        Message msg = parseMessage(buffer);

        std::cout << msg.pseudo << ": " << msg.content << "\n";

        // Broadcast à tous
        broadcast(buildMessage(msg.type, msg.pseudo, msg.content));
    }

    // Retirer le client
    {
        std::lock_guard<std::mutex> lock(clientsMutex);
        clients.erase(std::remove(clients.begin(), clients.end(), clientSocket), clients.end());
    }

    std::cout << "Client déconnecté\n";
    closeSocket(clientSocket);
}

void Server::broadcast(const std::string& message) {
    std::lock_guard<std::mutex> lock(clientsMutex);
    for (auto client : clients) {
        send(client, message.c_str(), message.size(), 0);
    }
}
