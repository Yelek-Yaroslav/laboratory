#include<stdio.h>
#include<float.h>

int main() {
    double X[16], Z[8];
    double min_Z = DBL_MAX;
    
    printf("Enter 16 real numbers:\n");
    for (int i = 0; i < 16; i+=1) {
        printf("X[%d]: ", i + 1);
        scanf("%lf", &X[i]);
    }
    
    for (int i = 0; i < 8; i+=1) {
        Z[i] = X[i] + X[15 - i];
        if (Z[i] < min_Z) {
            min_Z = Z[i];
        }
    }
    
    printf("Z array: ");
    for (int i = 0; i < 8; i+=1) {
        printf("%.2f ", Z[i]);
    }
    printf("\nMinimum element in Z: %.2f\n", min_Z);
    
    return 0;
}
