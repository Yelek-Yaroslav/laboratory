#include <stdio.h>
#include <math.h>

double add(double a, double b)       { return a + b; }
double subtract(double a, double b)  { return a - b; }
double multiply(double a, double b)  { return a * b; }
double divide(double a, double b) {
    if (b != 0) return a / b;
    else {
        printf("Warning: Division by zero!\n");
        return 0;
    }
}
double power(double a, double b)     { return pow(a, b); }

int main() {
    double (*operations[5])(double, double) = {add, subtract, multiply, divide, power};
    const char* names[5] = {"Add", "Subtract", "Multiply", "Divide", "Power"};

    double a, b;
    int choice;

    printf("Enter two numbers (a and b):\n");
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);

    while (1) {
        printf("\nChoose operation:\n");
        for (int i = 0; i < 5; i++)
            printf("%d - %s\n", i + 1, names[i]);
        printf("6 - All operations\n");
        printf("0 - Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting program.\n");
            break;
        } else if (choice >= 1 && choice <= 5) {
            double result = operations[choice - 1](a, b);
            printf("Result of %s(%.2f, %.2f) = %.4f\n",
                   names[choice - 1], a, b, result);
        } else if (choice == 6) {
            printf("Executing all operations:\n");
            for (int i = 0; i < 5; i++) {
                double result = operations[i](a, b);
                printf("%s(%.2f, %.2f) = %.4f\n", names[i], a, b, result);
            }
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
