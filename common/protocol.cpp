#include "protocol.h"
#include <sstream>
#include <vector>
#include <algorithm>

// Fonction utilitaire : séparer une string par un délimiteur
static std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, delimiter)) {
        result.push_back(item);
    }
    return result;
}

// Construire un message sous forme de string à envoyer via socket
std::string buildMessage(MessageType type, const std::string& pseudo, const std::string& content) {
    std::string typeStr;
    switch (type) {
        case MessageType::CONNECT:    typeStr = "CONNECT"; break;
        case MessageType::MSG:        typeStr = "MSG"; break;
        case MessageType::WIZZ:       typeStr = "WIZZ"; break;
        case MessageType::DISCONNECT: typeStr = "DISCONNECT"; break;
        default:                      typeStr = "UNKNOWN"; break;
    }
    return typeStr + "|" + pseudo + "|" + content + "\n";
}

// Parser un message reçu via socket
Message parseMessage(const std::string& raw) {
    Message msg;
    msg.type = MessageType::UNKNOWN;
    msg.pseudo = "";
    msg.content = "";

    // Supprimer le \n final si présent
    std::string clean = raw;
    clean.erase(std::remove(clean.begin(), clean.end(), '\n'), clean.end());

    auto parts = split(clean, '|');
    if (parts.empty()) return msg;

    // Type du message
    if (parts[0] == "CONNECT") msg.type = MessageType::CONNECT;
    else if (parts[0] == "MSG") msg.type = MessageType::MSG;
    else if (parts[0] == "WIZZ") msg.type = MessageType::WIZZ;
    else if (parts[0] == "DISCONNECT") msg.type = MessageType::DISCONNECT;
    else msg.type = MessageType::UNKNOWN;

    if (parts.size() > 1) msg.pseudo = parts[1];
    if (parts.size() > 2) msg.content = parts[2];

    return msg;
}
