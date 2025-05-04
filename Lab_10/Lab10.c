#include <stdio.h>
#include <math.h>

#define Nx 5
#define Ny 6
#define Nz 4

void vvod(float arr[], int n, char name);
void analiz(float arr[], int n, float *geom_avg, float *arith_avg);

int main() {
    float x[Nx], y[Ny], z[Nz];
    float geom, arith;

    vvod(x, Nx, 'x');
    analiz(x, Nx, &geom, &arith);
    printf("Array x: geom_avg = %.2f, arith_avg = %.2f\n", geom, arith);

    vvod(y, Ny, 'y');
    analiz(y, Ny, &geom, &arith);
    printf("Array y: geom_avg = %.2f, arith_avg = %.2f\n", geom, arith);

    vvod(z, Nz, 'z');
    analiz(z, Nz, &geom, &arith);
    printf("Array z: geom_avg = %.2f, arith_avg = %.2f\n", geom, arith);

    return 0;
}

void vvod(float arr[], int n, char name) {
    for (int i = 0; i < n; i++) {
        printf("Enter %c[%d]: ", name, i);
        scanf("%f", &arr[i]);
    }
}

void analiz(float arr[], int n, float *geom_avg, float *arith_avg) {
    float prod_pos = 1.0, sum_neg = 0.0;
    int count_pos = 0, count_neg = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            prod_pos *= arr[i];
            count_pos++;
        } else if (arr[i] < 0) {
            sum_neg += arr[i];
            count_neg++;
        }
    }

    if (count_pos > 0)
        *geom_avg = pow(prod_pos, 1.0 / count_pos);
    else
        *geom_avg = 0.0;

    if (count_neg > 0)
        *arith_avg = sum_neg / count_neg;
    else
        *arith_avg = 0.0;
}