#include <stdio.h>
#include <stdlib.h> // Для malloc і free

int main() {
    int size;
    printf("Enter the size of the vector: ");
    scanf("%d", &size);

    int *A = (int*)malloc(size * sizeof(int));
    int *B = (int*)malloc(size * sizeof(int));
    int *C = (int*)malloc(size * sizeof(int));

    if (A == NULL || B == NULL || C == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < size; i++) {
        printf("Enter element %d for vector A: ", i + 1);
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < size; i++) {
        B[i] = 3 * A[i];
        C[i] = 4 * A[i];
    }
    printf("Vector A: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\nVector B (3*A): ");
    for (int i = 0; i < size; i++) {
        printf("%d ", B[i]);
    }
     printf("\nVector C (4*A): ");
    for (int i = 0; i < size; i++) {
        printf("%d ", C[i]);
    }

    printf("\n");
    free(A);
    free(B);
    free(C);
    return 0;
}