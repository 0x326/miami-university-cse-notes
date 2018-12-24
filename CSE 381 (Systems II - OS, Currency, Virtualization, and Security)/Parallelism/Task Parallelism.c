#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sumI = 0;
int sumISquared = 0;
int sumICubed = 0;

void *computeSumI(void *arg_pointer) {
    int n = *((int *) arg_pointer);
    sumI = n * (n + 1) / 2;

    return NULL;
    // or, pthread_exit(NULL);
}

void *computeSumISquared(void *arg_pointer) {
    int n = *((int *) arg_pointer);
    sumISquared = n * (n + 1) * (2 * n + 1) / 6;

    return NULL;
    // or, pthread_exit(NULL);
}

void *computeSumICubed(void *arg_pointer) {
    int n = *((int *) arg_pointer);
    sumICubed = n * (n + 1) / 2;
    sumICubed *= sumICubed;

    return NULL;
    // or, pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s N\n", argv[0]);
        return EXIT_FAILURE;
    }

    int n = atoi(argv[1]);
    if (n < 0) {
        fputs("N must be non-negative", stderr);
        return EXIT_FAILURE;
    }

    pthread_attr_t sumThreadAttr;
    pthread_attr_t sumSquaredThreadAttr;
    pthread_attr_t sumCubedThreadAttr;

    pthread_attr_init(&sumThreadAttr);
    pthread_attr_init(&sumSquaredThreadAttr);
    pthread_attr_init(&sumCubedThreadAttr);

    pthread_t sumThreadId;
    pthread_t sumSquaredThreadId;
    pthread_t sumCubedThreadId;

    pthread_create(&sumThreadId, &sumThreadAttr, computeSumI, &n);
    pthread_create(&sumSquaredThreadId, &sumSquaredThreadAttr, computeSumISquared, &n);
    pthread_create(&sumCubedThreadId, &sumCubedThreadAttr, computeSumICubed, &n);

    pthread_join(sumThreadId, NULL);
    pthread_join(sumSquaredThreadId, NULL);
    pthread_join(sumCubedThreadId, NULL);

    printf("Σ i  = %d\n", sumI);
    printf("Σ i² = %d\n", sumISquared);
    printf("Σ i³ = %d\n", sumICubed);
}
