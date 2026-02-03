#include <iostream>
#include <cstring>
#include <string>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sock;
    sockaddr_in server_addr{};
    char buffer[1024];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    connect(sock, (sockaddr*)&server_addr, sizeof(server_addr));

    std::cout << "Conectado al servidor con exito. Escribe 'exit' para salir.\n";

    while (true) {
        std::string mensaje;
        std::cout << "> ";
        std::getline(std::cin, mensaje);

        send(sock, mensaje.c_str(), mensaje.size(), 0);

        if (mensaje == "exit") {
            std::cout << "Cerrando cliente...\n";
            break;
        }

        memset(buffer, 0, sizeof(buffer));
        recv(sock, buffer, sizeof(buffer), 0);
        std::cout << "Servidor: " << buffer << std::endl;
    }

    close(sock);
    return 0;
}
