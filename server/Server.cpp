#include "Server.hpp"
#include <QDebug>

Server::Server(QObject* parent, quint16 port) : QObject(parent), serverPort(port)
{
    tcpServer = new QTcpServer(this);
    clientManager = new Client_Manager();
}

void Server::start()
{
    if(!tcpServer->listen(QHostAddress::Any, serverPort))
    {
        qDebug() << "Impossible de démarrer le serveur";
        return;
    }
    qDebug() << "Serveur démarré sur le port" << serverPort;

    connect(tcpServer, &QTcpServer::newConnection, this, &Server::newConnection);
}

void Server::newConnection()
{
    QTcpSocket* clientSocket = tcpServer->nextPendingConnection();
    clientManager->addClient(clientSocket);
    qDebug() << "Nouveau client connecté !";
}