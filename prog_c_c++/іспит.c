#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 50
#define LOC_LEN  50

// Структура підприємства
typedef struct {
    char name[NAME_LEN];
    char location[LOC_LEN];
    float funds;
} Company;

int main() {
    int n;
    FILE *file;

    printf("Enter number of companies: ");
    scanf("%d", &n);

    // Виділяємо памʼять під масив структур
    Company* companies = (Company*)malloc(n * sizeof(Company));
    if (companies == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Ввід даних з клавіатури
    for (int i = 0; i < n; i++) {
        printf("\nCompany #%d\n", i + 1);
        printf("Enter name: ");
        scanf(" %[^\n]", companies[i].name);  // зчитування з пробілами
        printf("Enter location: ");
        scanf(" %[^\n]", companies[i].location);
        printf("Enter funds: ");
        scanf("%f", &companies[i].funds);
    }

    // Запис у файл
    file = fopen("companies.dat", "wb");
    if (file == NULL) {
        printf("Cannot open file for writing.\n");
        free(companies);
        return 1;
    }

    fwrite(companies, sizeof(Company), n, file);
    fclose(file);

    printf("\nData written to file successfully.\n");

    // Зчитування з файлу
    file = fopen("companies.dat", "rb");
    if (file == NULL) {
        printf("Cannot open file for reading.\n");
        free(companies);
        return 1;
    }

    fread(companies, sizeof(Company), n, file);
    fclose(file);

    // Оновлення вартості фондів
    for (int i = 0; i < n; i++) {
        printf("\nUpdating funds for %s (was %.2f)", companies[i].name, companies[i].funds);
        printf("\nEnter new funds: ");
        scanf("%f", &companies[i].funds);
    }

    // Повторний запис у файл
    file = fopen("companies.dat", "wb");
    if (file == NULL) {
        printf("Cannot reopen file for updating.\n");
        free(companies);
        return 1;
    }

    fwrite(companies, sizeof(Company), n, file);
    fclose(file);

    printf("\nUpdated data saved to file.\n");

    free(companies);
    return 0;
}
