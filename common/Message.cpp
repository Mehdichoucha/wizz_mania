#include "Message.hpp"
#include <QStringList>

QString Message::serialize() const
{
    QString typeStr;
    switch(type)
    {
        case MessageType::TEXT: typeStr = "TEXT"; break;
        case MessageType::WIZZ: typeStr = "WIZZ"; break;
        case MessageType::GAME: typeStr = "GAME"; break;
    }
    return typeStr + "|" + content;
}

Message Message::deserialize(const QString& data)
{
    QStringList parts = data.split("|");
    if(parts.size() != 2)
        return Message();

    MessageType t = MessageType::TEXT;
    if(parts[0] == "TEXT") t = MessageType::TEXT;
    else if(parts[0] == "WIZZ") t = MessageType::WIZZ;
    else if(parts[0] == "GAME") t = MessageType::GAME;

    return Message(t, parts[1]);
}