#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 100

typedef struct {
    char brand[MAX_STR];
    char bottlingPlace[MAX_STR];
    float strength;
    float volume;
    char color[MAX_STR];
    float price;
} Wine;

int main() {
    int n;
    printf("Enter the number of wines: ");
    scanf("%d", &n);

    Wine *wines = malloc(n * sizeof(Wine));
    if (wines == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nWine #%d\n", i + 1);
        printf("Brand: ");
        scanf(" %[^\n]", wines[i].brand);
        printf("Bottling place: ");
        scanf(" %[^\n]", wines[i].bottlingPlace);
        printf("Strength (%%): ");
        scanf("%f", &wines[i].strength);
        printf("Volume (L): ");
        scanf("%f", &wines[i].volume);
        printf("Color: ");
        scanf(" %[^\n]", wines[i].color);
        printf("Price: ");
        scanf("%f", &wines[i].price);
    }

    FILE *f = fopen("wines.txt", "w");
    if (f == NULL) {
        printf("File opening error!\n");
        free(wines);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(f, "%s | %s | %.2f%% | %.2fL | %s | %.2f\n",
                wines[i].brand,
                wines[i].bottlingPlace,
                wines[i].strength,
                wines[i].volume,
                wines[i].color,
                wines[i].price);
    }

    fclose(f);

    printf("\n--- Update wine prices ---\n");
    for (int i = 0; i < n; i++) {
        printf("New price for \"%s\": ", wines[i].brand);
        scanf("%f", &wines[i].price);
    }

    f = fopen("wines.txt", "w");
    if (f == NULL) {
        printf("File reopening error!\n");
        free(wines);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(f, "%s | %s | %.2f%% | %.2fL | %s | %.2f\n",
                wines[i].brand,
                wines[i].bottlingPlace,
                wines[i].strength,
                wines[i].volume,
                wines[i].color,
                wines[i].price);
    }

    fclose(f);
    free(wines);
    return 0;
}
