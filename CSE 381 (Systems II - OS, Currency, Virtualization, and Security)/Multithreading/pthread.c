// Compile with -pthread

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void* thread_runner(void *args_pointer) {
    printf("Thread created with parameters located at %p\n", args_pointer);

    // Do something

    void *return_value_pointer = args_pointer;
    return return_value_pointer;
    // or, pthread_exit(return_value_pointer);
}

#define THREADS 10

int main(int argc, char *argv[]) {
    pthread_t threads[THREADS];

    for (int i = 0; i < THREADS; i++) {
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        void *thread_args_pointer = 0;
        printf("Creating thread %d with parameters located at %p\n", i, thread_args_pointer);
        pthread_create(&(threads[i]), &attr, &thread_runner, thread_args_pointer);
    }

    for (int i = 0; i < THREADS; i++) {
        void *return_value_pointer;
        pthread_join(threads[i], &return_value_pointer);
        printf("Thread %d exited with a value located at %p\n", i, return_value_pointer);
    }

    puts("Main thread done");
    return EXIT_SUCCESS;
}
