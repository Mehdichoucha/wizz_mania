#include <QApplication>
#include "Client.hpp"
#include "ChatWindow.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Client client;
    client.connectToServer("127.0.0.1", 1234);

    ChatWindow window(&client);
    window.show();

    return a.exec();
}