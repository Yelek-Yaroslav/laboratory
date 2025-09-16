#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

typedef struct {
    char name[50];
    char location[50];
    float price;
} Camping;

int main() {
    Camping camps[SIZE] = {
        {"Sunny Camp", "Carpathians", 250.0},
        {"Forest Edge", "Poltava", 180.0},
        {"Lakeview", "Shatsk", 220.0},
        {"Mountain Base", "Carpathians", 300.0},
        {"River Camp", "Poltava", 150.0}
    };

    char desired_location[50];
    float max_price;
    FILE *out = fopen("filtered_campings.txt", "w");
    if (!out) {
        perror("Cannot open file");
        return 1;
    }

    printf("Available locations:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("- %s\n", camps[i].location);
    }

    printf("\nEnter desired location: ");
    scanf("%s", desired_location);
    printf("Enter maximum acceptable price per day: ");
    scanf("%f", &max_price);

    int found = 0;
    fprintf(out, "Campings in %s with price below %.2f:\n\n", desired_location, max_price);
    for (int i = 0; i < SIZE; i++) {
        if (strcmp(camps[i].location, desired_location) == 0 && camps[i].price < max_price) {
            fprintf(out, "Name: %s\nLocation: %s\nPrice per day: %.2f\n\n",
                    camps[i].name, camps[i].location, camps[i].price);
            found = 1;
        }
    }

    if (!found) {
        fprintf(out, "No campings match the criteria.\n");
    }

    fclose(out);
    printf("Filtered data written to filtered_campings.txt\n");

    return 0;
}
