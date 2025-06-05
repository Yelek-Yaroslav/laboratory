#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 50

typedef struct {
    char name[MAX_STR];
    char color[MAX_STR];
    float price;
} Flower;

int main() {
    int n;
    printf("Enter number of flowers: ");
    scanf("%d", &n);

    Flower *flowers = malloc(n * sizeof(Flower));
    if (flowers == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nFlower #%d\n", i + 1);
        printf("Name: ");
        scanf("%s", flowers[i].name);
        printf("Color: ");
        scanf("%s", flowers[i].color);
        printf("Price: ");
        scanf("%f", &flowers[i].price);
    }

    FILE *f = fopen("flowers.txt", "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        free(flowers);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(f, "%s %s %.2f\n", flowers[i].name, flowers[i].color, flowers[i].price);
    }

    fclose(f);
    printf("\nData saved to 'flowers.txt'.\n");

    for (int i = 0; i < n; i++) {
        printf("Enter new price for flower \"%s\": ", flowers[i].name);
        scanf("%f", &flowers[i].price);
    }

    f = fopen("flowers.txt", "w");
    if (f == NULL) {
        printf("Error reopening file!\n");
        free(flowers);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(f, "%s %s %.2f\n", flowers[i].name, flowers[i].color, flowers[i].price);
    }

    fclose(f);
    free(flowers);
    printf("\nFile updated with new prices.\n");

    return 0;
}
