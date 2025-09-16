#include <stdio.h>
#include <string.h>

#define MAX_CARS 100
#define MAX_STR 50

typedef struct {
    char brand[MAX_STR];
    char number[MAX_STR];
    char color[MAX_STR];
    float price;
} Car;

int main() {
    Car cars[MAX_CARS];
    int n;
    char searchBrand[MAX_STR];
    FILE *fout = fopen("output.txt", "w");

    if (fout == NULL) {
        printf("File opening error!\n");
        return 1;
    }

    printf("Enter the number of cars: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nCar #%d:\n", i + 1);
        printf("Brand: ");
        scanf("%s", cars[i].brand);
        printf("Number: ");
        scanf("%s", cars[i].number);
        printf("Color: ");
        scanf("%s", cars[i].color);
        printf("Price: ");
        scanf("%f", &cars[i].price);
    }

    printf("\nEnter brand to search: ");
    scanf("%s", searchBrand);

    printf("\nCars of brand \"%s\":\n", searchBrand);
    fprintf(fout, "Cars of brand \"%s\":\n", searchBrand);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(cars[i].brand, searchBrand) == 0) {
            printf("Brand: %s, Number: %s, Color: %s, Price: %.2f\n",
                   cars[i].brand, cars[i].number, cars[i].color, cars[i].price);
            fprintf(fout, "Brand: %s, Number: %s, Color: %s, Price: %.2f\n",
                    cars[i].brand, cars[i].number, cars[i].color, cars[i].price);
            found = 1;
        }
    }

    if (!found) {
        printf("No cars of this brand found.\n");
        fprintf(fout, "No cars of this brand found.\n");
    }

    fclose(fout);
    return 0;
}
