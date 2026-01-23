#ifndef SOCKET_UTILS_H
#define SOCKET_UTILS_H

#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    using socket_t = SOCKET;
#else
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    using socket_t = int;
#endif

bool initSockets();
void cleanupSockets();
void closeSocket(socket_t sock);

#endif
