#include <stdio.h>
#include <stdlib.h>
#include "distance.h"

int main() {
    int N;
    printf("Enter the number of points: ");
    scanf("%d", &N);

    if (N < 2) {
        printf("There must be at least two points to calculate distances.\n");
        return 1;
    }

    float** points = (float**)malloc(N * sizeof(float*));
    for (int i = 0; i < N; i++) {
        points[i] = (float*)malloc(2 * sizeof(float));
    }

    printf("Enter the coordinates of the points (x, y):\n");
    for (int i = 0; i < N; i++) {
        printf("Point %d: ", i + 1);
        scanf("%f %f", &points[i][0], &points[i][1]);
    }

    printf("\nDistances between consecutive points:\n");
    for (int i = 0; i < N - 1; i++) {
        float distance = calculate_distance(points[i][0], points[i][1], points[i + 1][0], points[i + 1][1]);
        printf("Distance between point %d and point %d: %.2f\n", i + 1, i + 2, distance);
    }

    for (int i = 0; i < N; i++) {
        free(points[i]);
    }
    free(points);

    return 0;
}
