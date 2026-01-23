#include "Client.h"
#include "socket_utils.h"
#include <iostream>

int main() {
    if (!initSockets()) { std::cerr << "Socket init failed\n"; return 1; }

    Client client("127.0.0.1", 12345);
    if (!client.connectToServer()) { cleanupSockets(); return 1; }

    client.listen();

    cleanupSockets();
    return 0;
}
