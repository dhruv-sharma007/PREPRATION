#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>

#define PORT 8001
#define BUFFER_SIZE 1024
#define REQ_SIZE 1024 * 10
#define APP_DIR "./appDir/"
#define NOT_FOUND_PAGE "./app/404.html"
#define MAX_LEN 512

// server =_socket can be used by cleanup
int server_socket;
void sendFile(const char *filePath, int client_socket);
void cleanup(int sig);

int main()
{
    int client_socket;
    struct sockaddr_in server_addr, client_addr;

    socklen_t client_addr_len = sizeof(client_addr);
    server_socket = socket(AF_INET, SOCK_STREAM, 0); // create socket

    (void)signal(SIGINT, cleanup); // handle ctrl+c

    if (server_socket == -1)
    {
        perror("Socket Creation Failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // bind socket to port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Bind Failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // listen for connections
    if (listen(server_socket, 5) < 0)
    {
        perror("Listen Failed\n");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server Started on PORT: %d\n", PORT);

    while (1)
    {
        // accept client
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0)
        {
            perror("Accept failed");
            continue;
        }
        char request[REQ_SIZE];
        ssize_t bytes_received = recv(client_socket, request, sizeof(request) - 1, 0);

        if (bytes_received > 0)
        {
            request[bytes_received] = '\0';
            char method[8], path[128], protocol[16];

            // parse request
            sscanf(request, "%s %s %s", method, path, protocol);
            char *file_path = (path[0] == '/') ? path + 1 : path;

            if (strlen(file_path) == 0)
            {
                sendFile("index.html", client_socket); // send index if no file
            }
            sendFile(file_path, client_socket); // send requested file
            printf("%s", request); // print request
        }
        close(client_socket); // close client socket
    }

    close(server_socket);

    return 0;
}

// function to send file to client
void sendFile(const char *filePath, int client_socket)
{
    char fullPath[MAX_LEN];
    snprintf(fullPath, MAX_LEN, "%s%s", APP_DIR, filePath);

    FILE *file_d = fopen(fullPath, "r");

    if (file_d == NULL)
    {
        // file not found
        const char *not_found = "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n"
                                "<h1>404 - File Not Found</h1>";
        send(client_socket, not_found, sizeof(not_found), 0);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    // send http header
    const char *http_header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
    send(client_socket, http_header, strlen(http_header), 0);

    // send file content
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file_d)))
    {
        ssize_t sent = send(client_socket, buffer, bytes_read, 0);
        if (sent < 0)
            break;
    }
    fclose(file_d);
}

// cleanup function for ctrl+c
void cleanup(int sig)
{

    printf("Cleaning up connections and exiting.\n");

    if (close(server_socket) < 0)
    {
        fprintf(stderr, "Error calling close()\n");
        exit(EXIT_FAILURE);
    }

    printf("Closing gracefully %d\n", sig);
    exit(EXIT_SUCCESS);
}
