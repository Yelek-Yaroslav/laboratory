#include <stdio.h>
#include <math.h>

float f(float a, float x, float b, int power) {
    return pow(a * x + b, power);
}

int main() {
    float a, b, x, omega, beta, y;

    printf("Enter values for:\n");
    printf("a = "); scanf("%f", &a);
    printf("x = "); scanf("%f", &x);
    printf("b = "); scanf("%f", &b);
    printf("beta = "); scanf("%f", &beta);
    printf("omega = "); scanf("%f", &omega);

    float denominator = f(pow(beta, 3), x, -omega, 1);

    if (denominator == 0) {
        printf("Error: Division by zero!\n");
    } else {
        y = (f(a, pow(x, 3), -b, 3) * f(2, pow(a, 3), 5, 4)) / denominator;
        printf("\nEvaluating the expression:\n");
        printf("y = (((a * x^3 - b)^3) * ((2 * a^3 + 5)^4)) / ((beta^3 * x - omega))\n");
        printf("y = (((%.2f * %.2f^3 - %.2f)^3) * ((2 * %.2f^3 + 5)^4)) / ((%.2f^3 * %.2f - %.2f))\n", a, x, b, a, beta, x, omega);
        printf("y = %.3f\n", y);
    }
    return 0;
}