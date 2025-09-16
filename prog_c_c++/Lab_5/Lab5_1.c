#include <stdio.h>

int main() {
    int N;
    float A[10][10];

    printf("Enter the size of the matrix N (N <= 10): ");
    scanf("%d", &N);

    if (N > 10 || N <= 0) {
        printf("Invalid value of N.\n");
        return 1;
    }

    printf("Enter the elements of the %d x %d matrix:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%f", &A[i][j]);
        }
    }

    printf("\nAverage of elements in each row:\n");
    for (int i = 0; i < N; i++) {
        float sum = 0.0;
        for (int j = 0; j < N; j++) {
            sum += A[i][j];
        }
        float average = sum / N;
        printf("Row %d: %.2f\n", i + 1, average);
    }

    return 0;
}