#include "Client.h"
#include "protocol.h"
#include <iostream>
#include <thread>
#include <cstring> // pour memset si besoin

Client::Client(const std::string& ip, int port) : serverIp(ip), serverPort(port) {}

bool Client::connectToServer() {
    socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFd < 0) return false;

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(serverPort);
    addr.sin_addr.s_addr = inet_addr(serverIp.c_str());

    if (connect(socketFd, (sockaddr*)&addr, sizeof(addr)) < 0) {
        return false;
    }
    return true;
}

void Client::sendMessage(const std::string& message) {
    std::string msg = buildMessage(MessageType::MSG, pseudo, message);
    send(socketFd, msg.c_str(), msg.size(), 0);
}

void Client::listen() {
    char buffer[1024];
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int bytesReceived = recv(socketFd, buffer, sizeof(buffer), 0);
        if (bytesReceived <= 0) break;

        Message msg = parseMessage(buffer);
        std::cout << msg.pseudo << ": " << msg.content << std::endl;
    }
    closeSocket(socketFd);
}
