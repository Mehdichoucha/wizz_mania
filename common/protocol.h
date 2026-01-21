#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <string>

enum class MessageType {
    CONNECT,
    MSG,
    WIZZ,
    DISCONNECT,
    UNKNOWN
};

struct Message {
    MessageType type;
    std::string pseudo;
    std::string content;
};

Message parseMessage(const std::string& raw);
std::string buildMessage(MessageType type,
                         const std::string& pseudo,
                         const std::string& content = "");

#endif
