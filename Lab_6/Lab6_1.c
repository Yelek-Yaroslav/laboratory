#include <stdio.h>

int main() {
    int M, N;
    float A[10][10];
    
    printf("Enter the number of rows M: ");
    scanf("%d", &M);
    printf("Enter the number of columns N: ");
    scanf("%d", &N);

    if (M > 10 || N > 10 || M <= 0 || N <= 0) {
        printf("Invalid matrix dimensions.\n");
        return 1;
    }

    printf("Enter the elements of matrix A[%d][%d]:\n", M, N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%f", &A[i][j]);
        }
    }

    for (int i = 0; i < M && i < N; i++) {
        float row_sum = 0.0;
        for (int j = 0; j < N; j++) {
            row_sum += A[i][j];
        }
        A[i][i] = row_sum;  
    }

    printf("\nMatrix A after replacement:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("A[%d][%d] = %.2f ", i, j, A[i][j]);
        }
        printf("\n");
    }

    return 0;
}