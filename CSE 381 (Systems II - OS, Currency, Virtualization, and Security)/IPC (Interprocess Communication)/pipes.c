#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(int argc, char **argv) {
    int pipe_file_descriptors[2];
    if (pipe(pipe_file_descriptors) == -1) {
        fprintf(stderr, "Cannot create pipe\n");  // Perhaps the system is out of file descriptors?
    }

    fflush(stdin);

    // In this example, the parent will write to the child
    pid_t child_pid = fork();
    if (child_pid > 0) {
        // Parent
        // In this example, the parent doesn't need the read end
        close(pipe_file_descriptors[READ_END]);

        // Send message to child
        char message[BUFFER_SIZE] = "Hello World\0";
        printf("Sending message: %s\n", message);
        write(pipe_file_descriptors[WRITE_END], message, strlen(message));

        // Close pipe when finished
        close(pipe_file_descriptors[WRITE_END]);
    } else if (child_pid == 0) {
        // Child
        // In this example, the child doesn't need the write end
        close(pipe_file_descriptors[WRITE_END]);

        // Read message from parent
        char message[BUFFER_SIZE];
        read(pipe_file_descriptors[READ_END], message, BUFFER_SIZE);
        printf("Got message: %s\n", message);

        // Close pipe when finished
        close(pipe_file_descriptors[READ_END]);
    } else {
        fputs("Cannot fork to create child process\n", stderr);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
