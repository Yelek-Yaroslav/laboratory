#include <stdio.h>
#include <stdlib.h>

float find_average_of_positive_elements(int *arr, int size) {
    int sum = 0;
    int count = 0;

    for (int *p = arr; p < arr + size; p++) {
        if (*p > 0) {
            sum += *p;
            count++;
        }
    }

    if (count == 0) {
        return 0;
    }

    return (float)sum / count;
}

int main() {
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    float average = find_average_of_positive_elements(arr, size);
    printf("The average of positive elements: %.2f\n", average);

    free(arr);

    return 0;
}
