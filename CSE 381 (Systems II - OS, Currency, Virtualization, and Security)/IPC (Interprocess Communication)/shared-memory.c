#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>

#define SHARED_MEMORY_OBJ_POSIX_ID "CSE381"
#define SHARED_MEMORY_OBJ_SIZE 4096

int main(int argc, char *argv[]) {
    pid_t child_pid = fork();
    if (child_pid > 0) {
        // You are the parent process - Your child's PID is child_pid
        const char *message_0 = "Hello";
        const char *message_1 = "World";

        // See https://en.wikipedia.org/wiki/Memory-mapped_file
        int file_descriptor_to_shared_memory_object = shm_open(SHARED_MEMORY_OBJ_POSIX_ID, O_CREAT | O_RDWR, 0666);
        ftruncate(file_descriptor_to_shared_memory_object, SHARED_MEMORY_OBJ_SIZE);
        void *pointer_to_shared_memory_object = mmap(0, SHARED_MEMORY_OBJ_SIZE, PROT_WRITE, MAP_SHARED, file_descriptor_to_shared_memory_object, 0);

        sprintf(pointer_to_shared_memory_object, "%s", message_0);
        pointer_to_shared_memory_object += strlen(message_0);
        sprintf(pointer_to_shared_memory_object, "%s", message_1);
        pointer_to_shared_memory_object += strlen(message_1);

        wait(NULL);

        shm_unlink(SHARED_MEMORY_OBJ_POSIX_ID);

        return EXIT_SUCCESS;
    } else if (child_pid == 0) {
        // You don't have a child process - You are the child

        // See https://en.wikipedia.org/wiki/Memory-mapped_file
        int file_descriptor_to_shared_memory_object = shm_open(SHARED_MEMORY_OBJ_POSIX_ID, O_RDONLY, 0666);
        ftruncate(file_descriptor_to_shared_memory_object, SHARED_MEMORY_OBJ_SIZE);
        void *pointer_to_shared_memory_object = mmap(0, SHARED_MEMORY_OBJ_SIZE, PROT_READ, MAP_SHARED, file_descriptor_to_shared_memory_object, 0);

        printf("%s\n", (char *) pointer_to_shared_memory_object);

        shm_unlink(SHARED_MEMORY_OBJ_POSIX_ID);
        return EXIT_SUCCESS;
    } else {
        fputs("Cannot fork to create child process", stderr);
        return EXIT_FAILURE;
    }
}
