#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793
#define NUM_VARIANTS 3
#define MAX_LINE_LENGTH 256

typedef struct {
    double T;
    double dt;
    double k0;
    double y;
    double e0;
    double r;
    double v;
} InputData;

double calculate_k(double t, double T, double k0, double y) {
    if (t <= T / 2.0)
        return k0 * (1 + y);
    else if (t <= T)
        return k0 * (1 - y);
    else {
        return 0.0;
    }
}

double calculate_e(double t, double T, double e0, double r) {
    if (t <= T / 2.0)
        return e0 * (1 + exp(-r * t));
    else if (t <= T)
        return e0 * (1 + exp(-r * T / 2.0));
    else {
        return 0.0;
    }
}

double calculate_B(float t, float T, float k0) {
    if (t <= T / 4.0)
        return k0 * t;
    else if (t <= 3 * T / 4.0)
        return (k0 * T / 4.0) - k0 * (t - T / 4.0);
    else {
        return 0.0;
    }
}

double calculate_LorentzForce(double e, double v, double B, double a) {
    return e * v * B * sin(a);
}

int main() {
    FILE *fin = fopen("input.txt", "r");
    if (!fin) {
        perror("Failed to open input.txt");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    fgets(line, sizeof(line), fin);

    InputData data[NUM_VARIANTS];
    int count = 0;

    while (count < NUM_VARIANTS &&
           fscanf(fin, "%lf %lf %lf %lf %lf %lf %lf",
                  &data[count].T,
                  &data[count].dt,
                  &data[count].k0,
                  &data[count].y,
                  &data[count].e0,
                  &data[count].r,
                  &data[count].v) == 7) {
        count++;
    }
    fclose(fin);

    if (count != NUM_VARIANTS) {
        fprintf(stderr, "Error: exactly %d variants are required.\n", NUM_VARIANTS);
        return 1;
    }

    FILE *fout = fopen("output.txt", "w");
    if (!fout) {
        perror("Failed to open output.txt");
        return 1;
    }

    for (int i = 0; i < NUM_VARIANTS; i++) {
        fprintf(fout, "Variant %d:\n", i + 1);
        printf("Variant %d:\n", i + 1);

        for (double t = 0; t <= data[i].T; t += data[i].dt) {
            double k = calculate_k(t, data[i].T, data[i].k0, data[i].y);
            double e = calculate_e(t, data[i].T, data[i].e0, data[i].r);
            double B = calculate_B(t, data[i].T, k);
            double alpha = PI / 2.0;
            double F = calculate_LorentzForce(e, data[i].v, B, alpha);

            fprintf(fout, "t = %.2f, B = %.6f, F = %.12f\n", t, B, F);
            printf("t = %.2f, B = %.6f, F = %.12f\n", t, B, F);
        }

        fprintf(fout, "\n");
        printf("\n");
    }

    fclose(fout);
    return 0;
}
