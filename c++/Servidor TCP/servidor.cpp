#include <iostream>
#include <cstring>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int server_fd, client_fd;
    sockaddr_in server_addr{};
    char buffer[1024];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    bind(server_fd, (sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_fd, 1);

    std::cout << "Servidor esperando conexión...\n";
    client_fd = accept(server_fd, nullptr, nullptr);
    std::cout << "Cliente conectado.\n";

    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int bytes = recv(client_fd, buffer, sizeof(buffer), 0);

        if (bytes <= 0) {
            std::cout << "Cliente desconectado.\n";
            break;
        }

        std::cout << "Cliente: " << buffer << std::endl;

        if (strcmp(buffer, "exit") == 0) {
            std::cout << "Comando exit recibido. Cerrando servidor...\n";
            break;
        }

        send(client_fd, "Mensaje recibido", 17, 0);
    }

    close(client_fd);
    close(server_fd);
    return 0;
}
