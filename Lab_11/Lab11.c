#include <stdio.h>

#define N1 6
#define N2 8
#define N3 5

void input(float arr[], int n, char name);
float average_positive(float arr[], int n);

int main() {
    float a[N1], b[N2], c[N3];
    float avg_a, avg_b, avg_c;

    input(a, N1, 'a');
    input(b, N2, 'b');
    input(c, N3, 'c');

    avg_a = average_positive(a, N1);
    avg_b = average_positive(b, N2);
    avg_c = average_positive(c, N3);

    printf("Average of positive elements in array a: %.2f\n", avg_a);
    printf("Average of positive elements in array b: %.2f\n", avg_b);
    printf("Average of positive elements in array c: %.2f\n", avg_c);

    return 0;
}

void input(float arr[], int n, char name) {
    for (int i = 0; i < n; i++) {
        printf("Enter %c[%d] = ", name, i + 1);
        scanf("%f", &arr[i]);
    }
}

float average_positive(float arr[], int n) {
    float sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            sum += arr[i];
            count++;
        }
    }

    if (count == 0)
        return 0; // no positive elements

    return sum / count;
}