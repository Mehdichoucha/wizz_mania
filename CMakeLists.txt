cmake_minimum_required(VERSION 3.10)
project(WizzMania)

set(CMAKE_CXX_STANDARD 17)

include_directories(common)

# Serveur
add_executable(wizz_server
    server/main.cpp
    server/Server.cpp
)

# Client
add_executable(wizz_client
    client/main.cpp
    client/Client.cpp
)
