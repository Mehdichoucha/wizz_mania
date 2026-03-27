#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <QString>

enum class MessageType {
    TEXT,
    WIZZ,
    GAME
};

struct Message
{
    MessageType type;
    QString content;

    // Constructeurs simples
    Message() : type(MessageType::TEXT), content("") {}
    Message(MessageType t, const QString& c) : type(t), content(c) {}

    // Convertir en QString pour envoyer sur le réseau
    QString serialize() const;
    static Message deserialize(const QString& data);
};

#endif // MESSAGE_HPP