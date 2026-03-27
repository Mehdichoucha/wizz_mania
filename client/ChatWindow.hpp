#ifndef CHATWINDOW_HPP
#define CHATWINDOW_HPP

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include "Client.hpp"

class ChatWindow : public QWidget
{
    Q_OBJECT

public:
    ChatWindow(Client* client, QWidget* parent = nullptr);

private slots:
    void sendMessage();
    void receiveMessage(const QString& message);

private:
    Client* client;
    QTextEdit* chatArea;
    QLineEdit* inputLine;
    QPushButton* sendButton;
};

#endif // CHATWINDOW_HPP