#include <stdio.h>

#define ROWS 3
#define COLS 4

void readMatrix(const char* filename, int matrix[ROWS][COLS]) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file %s\n", filename);
        return;
    }
    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLS; ++j)
            fscanf(file, "%d", &matrix[i][j]);
    fclose(file);
}

void writeMatrix(const char* filename, int matrix[ROWS][COLS]) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Failed to create file %s\n", filename);
        return;
    }
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j)
            fprintf(file, "%d ", matrix[i][j]);
        fprintf(file, "\n");
    }
    fclose(file);
}

int main() {
    int matrix1[ROWS][COLS];
    int matrix2[ROWS][COLS];
    int result[ROWS][COLS];
    int scalar;

    readMatrix("matrix1.txt", matrix1);
    readMatrix("matrix2.txt", matrix2);

    printf("Enter a number: ");
    scanf("%d", &scalar);

    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLS; ++j)
            result[i][j] = matrix2[i][j] - matrix1[i][j] * scalar;

    writeMatrix("exit.txt", result);

    printf("Result saved to exit.txt\n");
    return 0;
}
