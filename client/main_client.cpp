#include "Client.h"

int main() {
    Client client("127.0.0.1", 12345);
    client.connectToServer();
    client.listen();
    return 0;
}
