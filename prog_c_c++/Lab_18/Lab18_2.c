#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100

void inputArray(double arr[], int *size, char name) {
    printf("Enter the number of elements for array %c: ", name);
    scanf("%d", size);
    for (int i = 0; i < *size; i++) {
        printf("%c[%d] = ", name, i);
        scanf("%lf", &arr[i]);
    }
}

void processArrayX(double x[], int n, double *s, double *p, double *A, double *B, double *C) {
    *s = 0;
    *p = 1;
    double sumSin = 0, sumCos = 0, sumTan = 0;
    for (int i = 0; i < n; i++) {
        *s += x[i];
        *p *= x[i];
        sumSin += x[i] * sin(x[i]);
        sumCos += x[i] * cos(x[i]);
        sumTan += x[i] * tan(x[i]);
    }
    *A = (*s) * sumSin;
    *B = (*p) * sumCos;
    *C = (*s + *p) * sumTan;
}

void processArrayY(double y[], int m, double *s, double *p, double *D, double *E, double *F) {
    *s = 0;
    *p = 1;
    double sumTan = 0, sumExp = 0, sumCos = 0;
    for (int i = 0; i < m; i++) {
        *s += y[i];
        *p *= y[i];
        sumTan += y[i] * tan(y[i]);
        sumExp += y[i] * exp(y[i]);
        sumCos += y[i] * cos(y[i]);
    }
    *D = (*s) * sumTan;
    *E = (*p) * sumExp;
    *F = (*s + *p) * sumCos;
}

int main() {
    double x[MAX_SIZE], y[MAX_SIZE];
    int n, m;
    double sx, px, sy, py;
    double A, B, C, D, E, F, gamma;

    inputArray(x, &n, 'x');
    inputArray(y, &m, 'y');

    processArrayX(x, n, &sx, &px, &A, &B, &C);
    processArrayY(y, m, &sy, &py, &D, &E, &F);

    double numerator = A + B * cos(C);
    double denominator = D + E * sin(F);

    if (fabs(denominator) < 1e-10) {
        printf("Error: Division by zero or very small denominator.\n");
    } else {
        gamma = numerator / denominator;
        printf("\nResult:\n");
        printf("gamma = %.6lf\n", gamma);
    }

    return 0;
}
