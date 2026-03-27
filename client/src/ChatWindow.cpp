#include "../ChatWindow.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

ChatWindow::ChatWindow(Client* clientObj, QWidget* parent) : QWidget(parent), client(clientObj)
{
    chatArea = new QTextEdit(this);
    chatArea->setReadOnly(true);

    inputLine = new QLineEdit(this);
    sendButton = new QPushButton("Envoyer", this);

    QHBoxLayout* bottomLayout = new QHBoxLayout();
    bottomLayout->addWidget(inputLine);
    bottomLayout->addWidget(sendButton);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(chatArea);
    mainLayout->addLayout(bottomLayout);

    setLayout(mainLayout);
    setWindowTitle("WIZZ Mania");

    connect(sendButton, &QPushButton::clicked, this, &ChatWindow::sendMessage);
    connect(client, &Client::messageReceived, this, &ChatWindow::receiveMessage);
}

void ChatWindow::sendMessage()
{
    QString text = inputLine->text();
    if(text.isEmpty()) return;

    client->sendMessage(text);
    inputLine->clear();
}

void ChatWindow::receiveMessage(const QString& message)
{
    if(message == "WIZZ_SIGNAL")
    {
        // Simple secousse : bouger la fenêtre
        move(x()+5, y()); 
        move(x()-5, y());
    }
    else
    {
        chatArea->append(message);
    }
}