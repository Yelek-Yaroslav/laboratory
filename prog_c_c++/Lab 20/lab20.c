#include <stdio.h>
#define N 10 

struct Record {
    int month;
    int day;
    float temperature;
};

int main() {
    struct Record data[N];
    int count = 0;

    printf("Enter data for %d days:\n", N);
    for (int i = 0; i < N; i++) {
        printf("\nRecord %d:\n", i + 1);
        printf("  Month: ");
        scanf("%d", &data[i].month);
        printf("  Day: ");
        scanf("%d", &data[i].day);
        printf("  Temperature: ");
        scanf("%f", &data[i].temperature);
    }

    printf("\nDates with temperature > 0:\n");
    for (int i = 0; i < N; i++) {
        if (data[i].temperature > 0) {
            printf("  %02d.%02d - %.2fC\n", data[i].day, data[i].month, data[i].temperature);
            count++;
        }
    }

    printf("\nTotal days with temperature > 0: %d\n", count);
    return 0;
}
