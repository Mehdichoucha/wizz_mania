#include "Client.h"
#include "socket_utils.h"
#include <iostream>

// ici socketFd est utilisé, PAS de variable globale

int main() {
    // Initialisation sockets (Windows uniquement, no-op sur macOS)
    if (!initSockets()) {
        std::cerr << "Erreur initialisation sockets" << std::endl;
        return 1;
    }

    Client client("127.0.0.1", 12345);

    if (!client.connectToServer()) {
        cleanupSockets();
        return 1;
    }

    client.listen();  // ou startListening() selon ton implémentation

    // Nettoyage sockets
    cleanupSockets();
    return 0;
}
