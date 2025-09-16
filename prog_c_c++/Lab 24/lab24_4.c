#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 100

typedef struct {
    char name[MAX_STR];
    float displacement;
    char material[MAX_STR];
    int crew;
    float speed;
} Vessel;

int main() {
    int n;
    printf("Enter the number of vessels: ");
    scanf("%d", &n);

    Vessel *vessels = malloc(n * sizeof(Vessel));
    if (vessels == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nVessel #%d\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", vessels[i].name);
        printf("Displacement (tons): ");
        scanf("%f", &vessels[i].displacement);
        printf("Hull material: ");
        scanf(" %[^\n]", vessels[i].material);
        printf("Crew members: ");
        scanf("%d", &vessels[i].crew);
        printf("Speed (knots): ");
        scanf("%f", &vessels[i].speed);
    }

    FILE *f = fopen("vessels.txt", "w");
    if (f == NULL) {
        printf("File opening error!\n");
        free(vessels);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(f, "%s | %.2f | %s | %d | %.2f\n",
                vessels[i].name,
                vessels[i].displacement,
                vessels[i].material,
                vessels[i].crew,
                vessels[i].speed);
    }

    fclose(f);

    printf("\n--- Update vessel speeds ---\n");
    for (int i = 0; i < n; i++) {
        printf("New speed for \"%s\": ", vessels[i].name);
        scanf("%f", &vessels[i].speed);
    }

    f = fopen("vessels.txt", "w");
    if (f == NULL) {
        printf("File reopening error!\n");
        free(vessels);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(f, "%s | %.2f | %s | %d | %.2f\n",
                vessels[i].name,
                vessels[i].displacement,
                vessels[i].material,
                vessels[i].crew,
                vessels[i].speed);
    }

    fclose(f);
    free(vessels);
    return 0;
}