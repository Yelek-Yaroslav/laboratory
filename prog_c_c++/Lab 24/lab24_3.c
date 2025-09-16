#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 100

typedef struct {
    char name[MAX_STR];
    char airport[MAX_STR];
    int passengers;
    float price;
} Airliner;

int main() {
    int n;
    printf("Enter the number of airliners: ");
    scanf("%d", &n);

    Airliner *airliners = malloc(n * sizeof(Airliner));
    if (airliners == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nAirliner #%d\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", airliners[i].name);
        printf("Airport: ");
        scanf(" %[^\n]", airliners[i].airport);
        printf("Number of passengers: ");
        scanf("%d", &airliners[i].passengers);
        printf("Price: ");
        scanf("%f", &airliners[i].price);
    }

    FILE *f = fopen("airliners.txt", "w");
    if (f == NULL) {
        printf("File opening error!\n");
        free(airliners);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(f, "%s | %s | %d | %.2f\n",
                airliners[i].name,
                airliners[i].airport,
                airliners[i].passengers,
                airliners[i].price);
    }

    fclose(f);

    printf("\n--- Update airliner prices ---\n");
    for (int i = 0; i < n; i++) {
        printf("New price for \"%s\": ", airliners[i].name);
        scanf("%f", &airliners[i].price);
    }

    f = fopen("airliners.txt", "w");
    if (f == NULL) {
        printf("File reopening error!\n");
        free(airliners);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(f, "%s | %s | %d | %.2f\n",
                airliners[i].name,
                airliners[i].airport,
                airliners[i].passengers,
                airliners[i].price);
    }

    fclose(f);
    free(airliners);
    return 0;
}
