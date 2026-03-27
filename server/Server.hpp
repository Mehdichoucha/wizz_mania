#ifndef SERVER_HPP
#define SERVER_HPP

#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>
#include "Client_Manager.hpp"

class Server : public QObject
{
    Q_OBJECT

public:
    Server(QObject* parent = nullptr, quint16 port = 1234);
    void start();

private:
    QTcpServer* tcpServer;
    Client_Manager* clientManager;
    quint16 serverPort;

private slots:
    void newConnection();
};

#endif // SERVER_HPP