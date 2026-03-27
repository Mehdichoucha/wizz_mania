#ifndef CLIENT_MANAGER_HPP
#define CLIENT_MANAGER_HPP

#include <QTcpSocket>
#include <QObject>
#include <QVector>

class Client_Manager : public QObject
{
    Q_OBJECT

public:
    Client_Manager(QObject* parent = nullptr);
    void addClient(QTcpSocket* client);
    void broadcast(const QString& message);

private slots:
    void clientDisconnected();
    void readMessage();

private:
    QVector<QTcpSocket*> clients;
};

#endif // CLIENT_MANAGER_HPP