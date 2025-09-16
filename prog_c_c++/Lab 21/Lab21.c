#include <stdio.h>

struct Point {
    double x;
    double y;
};

void computeLine(struct Point p1, struct Point p2, double* a, double* b) {
    if (p1.x == p2.x) {
        printf("Error: vertical line, slope is undefined.\n");
        *a = 0;
        *b = 0;
        return;
    }

    *a = (p2.y - p1.y) / (p2.x - p1.x);
    *b = p1.y - (*a) * p1.x;
}

int main() {
    struct Point p1, p2;
    double a, b;

    printf("Enter coordinates of point 1 (x y): ");
    scanf("%lf %lf", &p1.x, &p1.y);

    printf("Enter coordinates of point 2 (x y): ");
    scanf("%lf %lf", &p2.x, &p2.y);

    computeLine(p1, p2, &a, &b);

    printf("Equation of the line: y = %.2fx + %.2f\n", a, b);

    return 0;
}
