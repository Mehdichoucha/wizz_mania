#include "Client_Manager.hpp"
#include <QDebug>

Client_Manager::Client_Manager(QObject* parent) : QObject(parent) {}

void Client_Manager::addClient(QTcpSocket* client)
{
    clients.append(client);
    connect(client, &QTcpSocket::readyRead, this, &Client_Manager::readMessage);
    connect(client, &QTcpSocket::disconnected, this, &Client_Manager::clientDisconnected);
}

void Client_Manager::readMessage()
{
    QTcpSocket* senderClient = qobject_cast<QTcpSocket*>(sender());
    if(!senderClient) return;

    QString message = QString(senderClient->readAll()).trimmed();
    qDebug() << "Message reçu:" << message;

    // Si message WIZZ
    if(message == "/wizz")
    {
        broadcast("WIZZ_SIGNAL");
    }
    else
    {
        broadcast(message);
    }
}

void Client_Manager::broadcast(const QString& message)
{
    for(QTcpSocket* client : clients)
    {
        client->write(message.toUtf8());
    }
}

void Client_Manager::clientDisconnected()
{
    QTcpSocket* client = qobject_cast<QTcpSocket*>(sender());
    if(client)
    {
        clients.removeOne(client);
        client->deleteLater();
        qDebug() << "Client déconnecté";
    }
}