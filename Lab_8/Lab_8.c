#include <stdio.h>

#define ROWS 3
#define COLS 4
#define VEC_SIZE 4

int main() {
    float matrix[ROWS][COLS];
    float vector[VEC_SIZE];
    float result[ROWS];

    printf("Enter the elements of a %dx%d matrix:\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("matrix[%d][%d] = ", i, j);
            scanf("%f", &matrix[i][j]);
        }
    }

    printf("Enter the elements of a %d-dimensional vector:\n", VEC_SIZE);
    for (int i = 0; i < VEC_SIZE; i++) {
        printf("vector[%d] = ", i);
        scanf("%f", &vector[i]);
    }

    for (int i = 0; i < ROWS; i++) {
        result[i] = 0;
        for (int j = 0; j < COLS; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }

    printf("\nResult of matrix-vector multiplication:\n");
    for (int i = 0; i < ROWS; i++) {
        printf("result[%d] = %.2f\n", i, result[i]);
    }

    float min = result[0];
    int min_index = 0;
    for (int i = 1; i < ROWS; i++) {
        if (result[i] < min) {
            min = result[i];
            min_index = i;
        }
    }

    printf("\nMinimum value: %.2f at index %d\n", min, min_index);

    return 0;
}
