#include <stdio.h>
#include <math.h>

double nested_sqrt(int k, int n) {
    if (k > n)
        return 0;
    return sqrt(2 * k - 1 + nested_sqrt(k + 1, n));
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    double result = nested_sqrt(1, n);
    printf("Result s = %.6lf\n", result);

    return 0;
}
