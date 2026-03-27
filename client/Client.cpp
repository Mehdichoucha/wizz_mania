#include "Client.hpp"
#include <QDebug>

Client::Client(QObject* parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &Client::readyRead);
    connect(socket, &QTcpSocket::disconnected, this, &Client::disconnected);
}

void Client::connectToServer(const QString& host, quint16 port)
{
    socket->connectToHost(host, port);
    if(socket->waitForConnected(3000))
    {
        qDebug() << "Connecté au serveur";
    }
    else
    {
        qDebug() << "Échec connexion";
    }
}

void Client::sendMessage(const QString& message)
{
    if(socket->state() == QAbstractSocket::ConnectedState)
        socket->write(message.toUtf8());
}

void Client::readyRead()
{
    QString message = QString(socket->readAll()).trimmed();
    emit messageReceived(message);
}

void Client::disconnected()
{
    qDebug() << "Déconnecté du serveur";
}