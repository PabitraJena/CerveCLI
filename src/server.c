#include <stdio.h>

#include <winsock2.h>

void server_start(){
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
    
    SOCKET server, client;
    struct sockaddr_in addr;
    char buffer[1024];

    server = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(9090);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(server, (struct sockaddr*)&addr, sizeof(addr));
    listen(server, 5);

    printf("Server running on http://localhost:9090\n");

    while (1){
        client = accept(server, NULL, NULL);

        recv(client, buffer, sizeof(buffer) - 1, 0);
        buffer[1023] = '\0';

        char *response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: 12\r\n"
            "Connection: close\r\n"
            "\r\n"
            "Hello World!";
        
        send(client, response, (int)strlen(response), 0);
        closesocket(client);
    }
    closesocket(server);
    WSACleanup();
}
