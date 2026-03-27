cmake_minimum_required(VERSION 3.16)
project(WizzMania)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)      # Qt MOC pour signaux/slots
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Chemins Qt
set(Qt6_DIR "C:/Qt/6.10.1/mingw_64/lib/cmake/Qt6")  # Ajuste selon ton installation
find_package(Qt6 REQUIRED COMPONENTS Core Network Widgets)

# ------------------
# Serveur
# ------------------
add_executable(Server
    server/Main_server.cpp
    server/Server.cpp
    server/Client_Manager.cpp
    common/Message.cpp
    server/Server.hpp
    server/Client_Manager.hpp
    common/Message.hpp
)

target_include_directories(Server PRIVATE
    server
    common
)

target_link_libraries(Server PRIVATE Qt6::Core Qt6::Network)

# ------------------
# Client
# ------------------
add_executable(Client
    client/Main_client.cpp
    client/Client.cpp
    client/ChatWindow.cpp
    common/Message.cpp
    client/Client.hpp
    client/ChatWindow.hpp
    common/Message.hpp
)

target_include_directories(Client PRIVATE
    client
    common
)

target_link_libraries(Client PRIVATE Qt6::Core Qt6::Network Qt6::Widgets)