#include "Server.h"
#include "socket_utils.h"
#include <iostream>

int main() {
    if (!initSockets()) { std::cerr << "Socket init failed\n"; return 1; }

    Server server(12345);
    server.start();

    cleanupSockets();
    return 0;
}
