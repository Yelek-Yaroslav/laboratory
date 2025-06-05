#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter matrix size (n): ");
    scanf("%d", &n);

    int **A = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        A[i] = malloc(n * sizeof(int));
    }

    printf("Enter elements of %d x %d matrix:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    int sum = 0;
    int product = 1;

    for (int i = 0; i < n; i++) {
        sum += A[i][i];
        product *= A[i][i];
        sum += A[i][n - 1 - i];
        product *= A[i][n - 1 - i];
    }

    if (n % 2 == 1) {
        int mid = n / 2;
        sum -= A[mid][mid];
        product /= A[mid][mid];
    }

    printf("Sum of diagonal elements: %d\n", sum);
    printf("Product of diagonal elements: %d\n", product);

    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);

    return 0;
}
