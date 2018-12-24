// Must be compiled with -fopenmp flag to enable OpenMP

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeMatrix(long long *matrix, const int rows, const int columns, const long long maxValue) {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            matrix[row * columns + column] = rand();
            if (maxValue > 0) {
                matrix[row * columns + column] %= maxValue;
            }
        }
    }
}

int addMatrices(long long *resultMatrix, const long long *matrixA, const int aRows, const int aColumns,
                const long long *matrixB, const int bRows, const int bColumns) {
    if (aRows == bRows && aColumns == bColumns) {
        const int n = aRows;
        const int m = aColumns;

#pragma omp parallel for
        for (int row = 0; row < n; row++) {
#pragma omp parallel for
            for (int column = 0; column < m; column++) {
                resultMatrix[row * m + column] = matrixA[row * m + column] + matrixB[row * m + column];
            }
        }
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int multiplyMatrices(long long *resultMatrix, const long long *matrixA, const int aRows, const int aColumns,
                     const long long *matrixB, const int bRows, const int bColumns) {
    if (aColumns != bRows) {
        return EXIT_FAILURE;
    }

    const int n = aRows;
    const int m = aColumns;
    const int p = bColumns;

#pragma omp parallel for
    for (int row = 0; row < n; row++) {
#pragma omp parallel for
        for (int column = 0; column < p; column++) {
            resultMatrix[row * p + column] = 0;
            for (int k = 0; k < m; k++) {
                resultMatrix[row * p + column] += matrixA[row * m + k] * matrixB[k * p + column];
            }
        }
    }

    return EXIT_SUCCESS;
}

void printMatrix(long long *matrix, int rows, int columns) {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            printf("%lli\t", matrix[row * columns + column]);
        }
        puts("");
    }
}

#define N 4
#define M 5
#define P 6

int main(int argc, char **argv) {
    srand((unsigned int) time(NULL));

    // Vector multipication
    // A is an n x m matrix
    long long matrixA[N][M];
    // B is an m x p matrix
    long long matrixB[M][P];
    // AB is an n x p matrix
    long long matrixAB[N][P];

    // Vector addition
    // X is an n x m matrix
    long long matrixX[N][M];
    // Y is an n x m matrix
    long long matrixY[N][M];
    // Z is an n x m matrix
    long long matrixZ[N][M];

    // Vector multipication
    initializeMatrix((long long *) matrixA, N, M, 100);
    initializeMatrix((long long *) matrixB, M, P, 100);

    // Vector addition
    initializeMatrix((long long *) matrixX, N, M, 100);
    initializeMatrix((long long *) matrixY, N, M, 100);

    clock_t endTime;
    clock_t startTime = clock();

    // Vector multipication
    multiplyMatrices((long long *) matrixAB, (const long long *) matrixA, N, M, (const long long *) matrixB, M, P);
    // Vector addition
    addMatrices((long long *) matrixZ, (const long long *) matrixX, N, M, (const long long *) matrixX, N, M);

    endTime = clock();

    // Vector multipication
    puts("Matrix A:");
    printMatrix((long long *) matrixA, N, M);
    puts("");

    puts("Matrix B:");
    printMatrix((long long *) matrixB, M, P);
    puts("");

    puts("Matrix AB:");
    printMatrix((long long *) matrixAB, N, P);
    puts("");

    // Vector addition
    puts("Matrix X:");
    printMatrix((long long *) matrixX, N, M);
    puts("");

    puts("Matrix Y:");
    printMatrix((long long *) matrixY, N, M);
    puts("");

    puts("Matrix X+Y:");
    printMatrix((long long *) matrixZ, N, M);
    puts("");

    printf("Elapsed CPU time: %f seconds", (endTime - startTime) * 1.0 / CLOCKS_PER_SEC);

    return EXIT_SUCCESS;
}
