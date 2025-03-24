#include <stdio.h>

void analyze_array(int N, const double arr[], double A, double B, int *zero_count, double *range_sum) {
    *zero_count = 0;
    *range_sum = 0;
    
    for (int i = 0; i < N; i+=1) {
        if (arr[i] == 0) {
            (*zero_count)+=1;
        }
        if (arr[i] >= A && arr[i] <= B) {
            *range_sum += arr[i];
        }
    }
}

int main() {
    int N;
    
    printf("Enter the number of array elements: ");
    while (scanf("%d", &N) != 1 || N <= 0) {
        printf("Invalid input. Enter a positive integer: ");
        while (getchar() != '\n');
    }
    
    double arr[N];
    for (int i = 0; i < N; i+=1) {
        printf("Element %d: ", i + 1);
        while (scanf("%lf", &arr[i]) != 1) {
            printf("Invalid input. Enter a valid number for Element %d: ", i + 1);
            while (getchar() != '\n');
        }
    }
    
    double A, B;
    printf("Enter A: ");
    while (scanf("%lf", &A) != 1) {
        printf("Invalid input. Enter a valid number for A: ");
        while (getchar() != '\n');
    }
    
    printf("Enter B: ");
    while (scanf("%lf", &B) != 1) {
        printf("Invalid input. Enter a valid number for B: ");
        while (getchar() != '\n');
    }
    
    if (A > B) {
        double temp = A;
        A = B;
        B = temp;
    }
    
    int zero_count;
    double range_sum;
    analyze_array(N, arr, A, B, &zero_count, &range_sum);
    
    printf("Number of elements equal to zero: %d\n", zero_count);
    printf("Sum of elements in the range [%.2lf, %.2lf]: %.2lf\n", A, B, range_sum);
    
    return 0;
}
