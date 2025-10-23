#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int mode;
    printf("Select input mode:\n1 - Standard data\n2 - Manual input\nYour choice: ");
    if (scanf("%d", &mode) != 1) return 1;

    int n;
    double **A, *b;
    if (mode == 1) {
        n = 4;
        double Astd[4][4] = {
            {-0.87,  0.22, -0.33,  0.07},
            { 0.00, -1.55, -0.23,  0.07},
            { 0.11,  0.00, -1.08,  0.78},
            { 0.08,  0.09,  0.33, -0.79}
        };
        double bstd[4] = {-0.11, 0.33, -0.85, 1.70};

        A = malloc(n * sizeof(double*));
        b = malloc(n * sizeof(double));
        for (int i = 0; i < n; i++) {
            A[i] = malloc(n * sizeof(double));
            for (int j = 0; j < n; j++) A[i][j] = Astd[i][j];
            b[i] = bstd[i];
        }
        printf("Standard matrix loaded (n = %d)\n", n);
    } 
    else if (mode == 2) {
        printf("Enter system size n: ");
        if (scanf("%d", &n) != 1 || n <= 0) return 1;

        A = malloc(n * sizeof(double*));
        b = malloc(n * sizeof(double));
        for (int i = 0; i < n; i++) {
            A[i] = malloc(n * sizeof(double));
            for (int j = 0; j < n; j++) {
                printf("A[%d][%d] = ", i+1, j+1);
                scanf("%lf", &A[i][j]);
            }
            printf("b[%d] = ", i+1);
            scanf("%lf", &b[i]);
        }
    } 
    else {
        printf("Invalid mode\n");
        return 1;
    }
for (int i = 0; i < n; i++) {
    if (fabs(A[i][i]) < 1e-12) {
        printf("Error: Zero element detected on the main diagonal at A[%d][%d].\n", i+1, i+1);
        printf("Cannot proceed with iteration methods.\n");
        for (int k = 0; k < n; k++) free(A[k]);
        free(A); free(b);
        return 1;
    }
}

int diag_dominant = 1;
for (int i = 0; i < n; i++) {
    double sum = 0.0;
    for (int j = 0; j < n; j++) {
        if (i != j) sum += fabs(A[i][j]);
    }
    if (fabs(A[i][i]) <= sum) {
        diag_dominant = 0;
        printf("Row %d is not diagonally dominant: |A[%d][%d]| = %.3f ≤ %.3f\n",
               i+1, i+1, i+1, fabs(A[i][i]), sum);
    }
}
if (!diag_dominant) {
    printf("\nWarning: The matrix is not diagonally dominant! "
           "The method may not converge.\n\n");
}

    int method;
    printf("\nSelect method:\n1 - Simple iterations\n2 - Seidel\nYour choice: ");
    if (scanf("%d", &method) != 1 || (method != 1 && method != 2)) return 1;

    double eps;
    printf("Enter tolerance: ");
    if (scanf("%lf", &eps) != 1 || eps <= 0) return 1;

    double **alpha = malloc(n * sizeof(double*));
    double *beta = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        alpha[i] = malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            if (i == j) alpha[i][j] = 0.0;
            else alpha[i][j] = -A[i][j] / A[i][i];
        }
        beta[i] = b[i] / A[i][i];
    }

    double normA = 0.0;
    for (int i = 0; i < n; i++) {
        double s = 0.0;
        for (int j = 0; j < n; j++) s += fabs(alpha[i][j]);
        if (s > normA) normA = s;
    }

    double *x = calloc(n, sizeof(double));
    double *x_old = calloc(n, sizeof(double));
    const int max_iter = 100000;
    int iter = 0;

    printf("\nIter      error\n");

    while (iter < max_iter) {
        iter++;
        for (int i = 0; i < n; i++) x_old[i] = x[i];

        if (method == 1) {
            for (int i = 0; i < n; i++) {
                double s = beta[i];
                for (int j = 0; j < n; j++) s += alpha[i][j] * x_old[j];
                x[i] = s;
            }
        } 
        else {
            for (int i = 0; i < n; i++) {
                double s = beta[i];
                for (int j = 0; j < n; j++) {
                    if (j != i) s += alpha[i][j] * x[j];
                }
                x[i] = s;
            }
        }

        double delta = 0.0;
        for (int i = 0; i < n; i++) {
            double d = fabs(x[i] - x_old[i]);
            if (d > delta) delta = d;
        }

        double err;
        if (method == 1)
            err = delta * normA / (1 - normA);
        else
            err = delta;

        printf("%4d   %.6e\n", iter, err);

        if (err < eps) break;
    }

    if (iter == max_iter) printf("\nWarning: Max iterations reached (%d)\n", max_iter);

    printf("\nConverged in %d iterations\nSolution:\n", iter);
    for (int i = 0; i < n; i++)
        printf("x[%d] = %.4f\n", i + 1, x[i]);

    for (int i = 0; i < n; i++) { free(A[i]); free(alpha[i]); }
    free(A); free(alpha); free(b); free(beta);
    free(x); free(x_old);
    return 0;
}