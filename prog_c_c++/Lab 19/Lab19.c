#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void inputArray(double* array, int size, char name) {
    printf("Enter %d elements for array %c:\n", size, name);
    for (int i = 0; i < size; i++) {
        printf("%c[%d] = ", name, i);
        scanf("%lf", &array[i]);
    }
}

void processAlpha(double* alpha, int n, double* A, double* B, double* s, double* p) {
    *A = 0;
    *B = 0;
    *s = 0;
    *p = 1;
    for (int i = 0; i < n; i++) {
        *s += alpha[i];
        *p *= alpha[i];
        if (alpha[i] <= 0) {
            *A += alpha[i] * sin(alpha[i]);
        } else {
            *B += alpha[i] * tan(alpha[i]);
        }
    }
    *A *= *s;
    *B *= *p;
}

void processBeta(double* beta, int m, double* D, double* C, double* s, double* p) {
    *D = 0;
    *C = 0;
    *s = 0;
    *p = 1;
    for (int i = 0; i < m; i++) {
        *s += beta[i];
        *p *= beta[i];
        if (beta[i] <= 0) {
            *D += beta[i] * cos(beta[i]);
        } else {
            *C += beta[i] * sin(beta[i]);
        }
    }
    *D *= *s;
    *C *= *p;
}

int main() {
    int n, m;
    printf("Enter the number of elements in array A: ");
    scanf("%d", &n);
    printf("Enter the number of elements in array B: ");
    scanf("%d", &m);

    double* alpha = (double*)malloc(n * sizeof(double));
    double* beta = (double*)malloc(m * sizeof(double));

    if (!alpha || !beta) {
        printf("Memory allocation error!\n");
        return 1;
    }

    inputArray(alpha, n, 'A');
    inputArray(beta, m, 'B');

    double A, B, s_alpha, p_alpha;
    double D, C, s_beta, p_beta;

    processAlpha(alpha, n, &A, &B, &s_alpha, &p_alpha);
    processBeta(beta, m, &D, &C, &s_beta, &p_beta);

    double denominator = sin(D) + sin(C);
    if (fabs(denominator) < 1e-8) {
        printf("Error: denominator is too close to zero.\n");
    } else {
        double gamma = (A + B) / denominator;
        printf("\nComputed Y = %.6lf\n", gamma);
    }

    free(alpha);
    free(beta);
    return 0;
}
