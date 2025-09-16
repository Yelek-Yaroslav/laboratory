#include <stdio.h>

int main() {
    int M, N;
    float K[10][10];
    float B[10];
    int count = 0;

    printf("Enter the number of rows M: ");
    scanf("%d", &M);
    printf("Enter the number of columns N: ");
    scanf("%d", &N);

    if (M > 10 || N > 10 || M <= 0 || N <= 0) {
        printf("Invalid matrix dimensions.\n");
        return 1;
    }

    printf("Enter the elements of matrix K[%d][%d]:\n", M, N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("K[%d][%d] = ", i, j);
            scanf("%f", &K[i][j]);
        }
    }

    for (int i = 1; i < M; i++) {
        if (i < N) {
            float product = 1.0;
            for (int j = 0; j < i; j++) {
                product *= K[i][j];
            }
            B[count++] = product;
        }
    }

    printf("\nArray B:\n");
    for (int i = 0; i < count; i++) {
        printf("B[%d] = %.2f\n", i, B[i]);
    }

    printf("Number of such rows: %d\n", count);

    return 0;
}