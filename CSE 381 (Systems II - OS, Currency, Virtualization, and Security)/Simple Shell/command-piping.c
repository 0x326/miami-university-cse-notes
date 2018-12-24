#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

#define READ_END 0
#define WRITE_END 1

int main() {
    // Example: "ls -l | wc -l"

    // Tokenize user input into the following form
    char **command_line[2];
    command_line[0] = (char *[]) {"ls", "-l", NULL};
    command_line[1] = (char *[]) {"wc", "-l", NULL};

    // Create pipe
    int pipe_file_descriptors[2];
    pipe(pipe_file_descriptors);

    // Fork child processes
    pid_t child_pid = fork();
    if (child_pid > 0) {
        // Parent

        // Close unused end of pipe
        close(pipe_file_descriptors[WRITE_END]);

        // Copies read end file descriptor to stdin
        dup2(pipe_file_descriptors[READ_END], STDIN_FILENO);

        // Replace the current process
        char **command = command_line[1];
        execvp(command[0], command);
    } else if (child_pid == 0) {
        // Child

        // Close unused end of pipe
        close(pipe_file_descriptors[READ_END]);

        // Copies write end file descriptor to stdout
        dup2(pipe_file_descriptors[WRITE_END], STDOUT_FILENO);

        // Replace the current process
        char **command = command_line[0];
        execvp(command[0], command);
    } else {
        fputs("Cannot fork to create child process", stderr);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
