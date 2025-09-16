#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void input_array(double *array, int size, char name) {
    printf("Enter %d elements for array %c:\n", size, name);
    for (int i = 0; i < size; i++) {
        printf("%c[%d] = ", name, i);
        scanf("%lf", &array[i]);
    }
}

double compute_value(char type, double *arr1, double *arr2, int size) {
    double result = 0.0;
    for (int i = 0; i < size; i++) {
        switch (type) {
            case 'A':
                result += arr1[i] * sin(fabs(arr1[i])) + pow(arr1[i], 2) * cos(arr1[i]);
                break;
            case 'B':
                result += arr1[i] * cos(fabs(arr1[i])) + pow(arr1[i], 2) * sin(arr1[i]);
                break;
            case 'C':
                result += arr1[i] * sin(fabs(arr1[i])) + pow(arr1[i], 2) * sin(arr2[i]);
                break;
            case 'D':
                result += arr1[i] * cos(fabs(arr1[i])) + pow(arr1[i], 2) * cos(arr1[i]);
                break;
            default:
                printf("Invalid type.\n");
                return 0.0;
        }
    }
    return result;
}

int main() {
    int n;
    char choice;

    printf("Select calculation (A, B, C or D): ");
    scanf(" %c", &choice);

    printf("Enter number of elements: ");
    scanf("%d", &n);

    double *x = malloc(n * sizeof(double));
    double *y = malloc(n * sizeof(double));
    double *z = malloc(n * sizeof(double));
    double *q = malloc(n * sizeof(double));

    switch (choice) {
        case 'A':
            input_array(x, n, 'x');
            printf("Result A = %.3lf\n", compute_value('A', x, NULL, n));
            break;
        case 'B':
            input_array(y, n, 'y');
            printf("Result B = %.3lf\n", compute_value('B', y, NULL, n));
            break;
        case 'C':
            input_array(z, n, 'z');
            input_array(y, n, 'y');
            printf("Result C = %.3lf\n", compute_value('C', z, y, n));
            break;
        case 'D':
            input_array(q, n, 'q');
            printf("Result D = %.3lf\n", compute_value('D', q, NULL, n));
            break;
        default:
            printf("Unknown operation.\n");
    }

    free(x);
    free(y);
    free(z);
    free(q);
    return 0;
}
