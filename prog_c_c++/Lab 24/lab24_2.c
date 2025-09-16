#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 100

typedef struct {
    char name[MAX_STR];
    char location[MAX_STR];
    float funds;
} Company;

int main() {
    int n;
    printf("Enter the number of companies: ");
    scanf("%d", &n);

    Company *companies = malloc(n * sizeof(Company));
    if (companies == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nCompany #%d\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", companies[i].name);
        printf("Location: ");
        scanf(" %[^\n]", companies[i].location);
        printf("Funds value: ");
        scanf("%f", &companies[i].funds);
    }

    FILE *f = fopen("companies.txt", "w");
    if (f == NULL) {
        printf("File opening error!\n");
        free(companies);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(f, "%s | %s | %.2f\n", companies[i].name, companies[i].location, companies[i].funds);
    }

    fclose(f);

    printf("\n--- Update funds ---\n");
    for (int i = 0; i < n; i++) {
        printf("New funds for \"%s\": ", companies[i].name);
        scanf("%f", &companies[i].funds);
    }

    f = fopen("companies.txt", "w");
    if (f == NULL) {
        printf("File reopening error!\n");
        free(companies);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(f, "%s | %s | %.2f\n", companies[i].name, companies[i].location, companies[i].funds);
    }

    fclose(f);
    free(companies);
    return 0;
}
