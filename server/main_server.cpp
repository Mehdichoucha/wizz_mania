#include <QCoreApplication>
#include "Server.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server(nullptr, 1234);
    server.start();

    return a.exec();
}