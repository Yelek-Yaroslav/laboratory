#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    printf("Enter the number of elements (N): ");
    scanf("%d", &N);

    int *A = malloc(N * sizeof(int));
    if (!A) return 1;

    for (int i = 0; i < N; i++) {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }

    printf("Enter the threshold value (M): ");
    scanf("%d", &M);

    int *B = malloc(N * sizeof(int));
    if (!B) {
        free(A);
        return 1;
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] > M) {
            B[count++] = A[i];
        }
    }

    printf("Filtered array:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");

    free(A);
    free(B);
    return 0;
}