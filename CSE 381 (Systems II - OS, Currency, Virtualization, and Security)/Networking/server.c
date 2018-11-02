#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <zconf.h>

#define BUFFER_SIZE 256
#define INCOMING_CONNECTIONS_TO_QUEUE 5

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    // Parse commandline parameters
    if (argc == 1) {
        fprintf(stdout, "Usage: %s PORT\n", argv[0]);
        fputs(stderr, "PORT is required\n");
        return EXIT_FAILURE;
    } else if (argc > 2) {
        fprintf(stdout, "Usage: %s PORT\n", argv[0]);
        fputs(stderr, "Too many arguments provided\n");
        return EXIT_FAILURE;
    }
    const int port_number = atoi(argv[1]);

    int socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_file_descriptor < 0) {
        fputs(stderr, "Cannot create IPv4 socket\n");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_address;

    bzero((char *) &server_address, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    server_address.sin_addr.s_addr = INADDR_ANY;

    char buffer[BUFFER_SIZE];

    // Listen
    if (bind(socket_file_descriptor, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        fputs(stderr, "Cannot bind socket\n");
        return EXIT_FAILURE;
    }
    listen(socket_file_descriptor, INCOMING_CONNECTIONS_TO_QUEUE);

    // Accept connection
    struct sockaddr_in client_address;
    socklen_t client_address_length = sizeof(client_address);
    int clientsocket_file_descriptor = accept(socket_file_descriptor, (struct sockaddr *) &client_address, &client_address_length);
    if (clientsocket_file_descriptor < 0) {
        fputs(stderr, "Cannot accept TCP connection from socket\n");
        return EXIT_FAILURE;
    }
    bzero(buffer, 256);

    // Read
    ssize_t bytesTransfered;
    bytesTransfered = read(clientsocket_file_descriptor, buffer, 255);
    if (bytesTransfered < 0) {
        fputs(stderr, "Cannot read from socket\n");
        return EXIT_FAILURE;
    }
    printf("Got message: %s\n", buffer);

    // Write
    bytesTransfered = write(clientsocket_file_descriptor, "Received message: ", 18);
    if (bytesTransfered < 0) {
        fputs(stderr, "Cannot write to socket\n");
        return EXIT_FAILURE;
    }
    bytesTransfered = write(clientsocket_file_descriptor, buffer, BUFFER_SIZE);
    if (bytesTransfered < 0) {
        fputs(stderr, "Cannot write to socket\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
