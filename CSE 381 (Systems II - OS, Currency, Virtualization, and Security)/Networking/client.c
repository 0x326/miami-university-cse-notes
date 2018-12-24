#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <zconf.h>
#include <string.h>

#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {
    // Parse commandline parameters
    if (argc < 3) {
        fprintf(stdout, "Usage: %s HOST PORT\n", argv[0]);
        if (argc < 2) {
            fputs("HOST is required", stderr);
        }
        fputs("PORT is required", stderr);
        return EXIT_FAILURE;
    } else if (argc > 2) {
        fprintf(stdout, "Usage: %s HOST PORT\n", argv[0]);
        fputs("Too many arguments provided", stderr);
        return EXIT_FAILURE;
    }

    struct hostent *host = gethostbyname(argv[1]);
    int port_number = atoi(argv[2]);

    if (host == NULL) {
        fputs("Cannot find specified host", stderr);
        return EXIT_FAILURE;
    }

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
    bcopy(host->h_addr,
          (char *) &server_address.sin_addr.s_addr,
          (size_t) host->h_length);

    // Apply socket configuration and connect to server
    if (connect(socket_file_descriptor, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        fputs("Cannot make TCP connection to server\n", stderr);
        return EXIT_FAILURE;
    }

    // Write
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);

    printf("Enter a message to send to the server: ");
    fgets(buffer, BUFFER_SIZE - 1, stdin);

    ssize_t bytes_transferred = write(socket_file_descriptor, buffer, strlen(buffer));
    if (bytes_transferred < 0) {
        fputs("Cannot write to socket\n", stderr);
        return EXIT_FAILURE;
    }

    // Read
    bzero(buffer, BUFFER_SIZE);
    bytes_transferred = read(socket_file_descriptor, buffer, BUFFER_SIZE - 1);
    if (bytes_transferred < 0) {
        fputs("Cannot read from socket\n", stderr);
        return EXIT_FAILURE;
    }
    printf("Got message in reply: %s\n", buffer);

    return EXIT_SUCCESS;
}
