#include <stdio.h>

int main() {
    int M;
    float A[10][10];
    float main_sum = 0.0, secondary_sum = 0.0, total_sum = 0.0;

    printf("Enter the order of the square matrix M: ");
    scanf("%d", &M);

    if (M > 10 || M <= 0) {
        printf("Invalid matrix size.\n");
        return 1;
    }

    printf("Enter the elements of matrix A[%d][%d]:\n", M, M);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%f", &A[i][j]);
        }
    }

    for (int i = 0; i < M; i++) {
        main_sum += A[i][i];
        secondary_sum += A[i][M - 1 - i];
    }

    if (M % 2 == 1) {
        total_sum = main_sum + secondary_sum - A[M / 2][M / 2];
    } 
    else {
        total_sum = main_sum + secondary_sum;
    }

    printf("\nSum of main diagonal: %.2f\n", main_sum);
    printf("Sum of secondary diagonal: %.2f\n", secondary_sum);
    printf("Total sum: %.2f\n", total_sum);

    return 0;
}
