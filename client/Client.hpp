#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <QTcpSocket>
#include <QObject>

class Client : public QObject
{
    Q_OBJECT

public:
    Client(QObject* parent = nullptr);
    void connectToServer(const QString& host = "127.0.0.1", quint16 port = 1234);
    void sendMessage(const QString& message);

signals:
    void messageReceived(const QString& message);

private slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket* socket;
};

#endif // CLIENT_HPP