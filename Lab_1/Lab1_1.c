#include <stdio.h>
#include <math.h>

int main() {
    int N;
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Invalid input. Number of elements must be greater than zero.\n");
        return 1;
    }

    int MAS[N];
    int sum_even = 0, count_even = 0;
    double avg_even;
    int prod_odd = 1, count_odd = 0;
    double geo_mean_odd;
    int max_val, max_index;

    for (int i = 0; i < N; i+=1) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &MAS[i]);
    }

    for (int i = 0; i < N; i+=1) {
        if (MAS[i] % 2 == 0) { 
            sum_even += MAS[i];
            count_even+=1;
        } else { 
            prod_odd *= MAS[i];
            count_odd+=1;
        }

        if (i == 0 || MAS[i] > max_val) {
            max_val = MAS[i];
            max_index = i;
        }
    }

    avg_even = (count_even > 0) ? (double)sum_even / count_even : 0;
    geo_mean_odd = (count_odd > 0) ? pow(prod_odd, 1.0 / count_odd) : 0;

    printf("Sum of even numbers: %d\n", sum_even);
    printf("Average of even numbers: %.2f\n", avg_even);
    printf("Product of odd numbers: %d\n", count_odd > 0 ? prod_odd : 0);
    printf("Geometric mean of odd numbers: %.2f\n", geo_mean_odd);
    printf("Maximum value: %d, its index: %d\n", max_val, max_index + 1);

    return 0;
}