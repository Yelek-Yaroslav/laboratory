#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 50
#define LOC_LEN  50

typedef struct {
    char name[NAME_LEN];
    char location[LOC_LEN];
    float funds;
} Company;

int main() {
    FILE* file = fopen("companies.dat", "rb");
    if (!file) {
        printf("Cannot open file.\n");
        return 1;
    }

    Company temp;
    int i = 1;
    while (fread(&temp, sizeof(Company), 1, file)) {
        printf("Company #%d\n", i++);
        printf("Name: %s\n", temp.name);
        printf("Location: %s\n", temp.location);
        printf("Funds: %.2f\n\n", temp.funds);
    }

    fclose(file);
    return 0;
}