#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <zconf.h>

#define BUFFER_SIZE 256
#define INCOMING_CONNECTIONS_TO_QUEUE 5

int main(int argc, char *argv[]) {
    // Parse commandline parameters
    if (argc == 1) {
        fprintf(stdout, "Usage: %s PORT\n", argv[0]);
        fputs("PORT is required\n", stderr);
        return EXIT_FAILURE;
    } else if (argc > 2) {
        fprintf(stdout, "Usage: %s PORT\n", argv[0]);
        fputs("Too many arguments provided\n", stderr);
        return EXIT_FAILURE;
    }
    const int port_number = atoi(argv[1]);

    int socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_file_descriptor < 0) {
        fputs("Cannot create IPv4 socket\n", stderr);
        return EXIT_FAILURE;
    }

    // Build socket configuration
    struct sockaddr_in server_address;
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Apply socket configuration and listen for connections
    if (bind(socket_file_descriptor, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        fputs("Cannot bind socket\n", stderr);
        return EXIT_FAILURE;
    }
    listen(socket_file_descriptor, INCOMING_CONNECTIONS_TO_QUEUE);

    // Accept connection
    struct sockaddr_in client_address;
    socklen_t client_address_length = sizeof(client_address);
    int client_socket_file_descriptor = accept(socket_file_descriptor, (struct sockaddr *) &client_address,
                                               &client_address_length);
    if (client_socket_file_descriptor < 0) {
        fputs("Cannot accept TCP connection from socket\n", stderr);
        return EXIT_FAILURE;
    }

    // Read
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    ssize_t bytes_transferred = read(client_socket_file_descriptor, buffer, BUFFER_SIZE - 1);
    if (bytes_transferred < 0) {
        fputs("Cannot read from socket\n", stderr);
        return EXIT_FAILURE;
    }
    printf("Got message: %s\n", buffer);

    // Write
    bytes_transferred = write(client_socket_file_descriptor, "Received message: ", 18);
    if (bytes_transferred < 0) {
        fputs("Cannot write to socket\n", stderr);
        return EXIT_FAILURE;
    }
    bytes_transferred = write(client_socket_file_descriptor, buffer, BUFFER_SIZE);
    if (bytes_transferred < 0) {
        fputs("Cannot write to socket\n", stderr);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
