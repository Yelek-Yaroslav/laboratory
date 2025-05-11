#include <stdio.h>

void transform_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] <= 0) {
            arr[i] = 0;
        }
    }
}

int main() {
    int x[50] = {1, -3, 5, 7, -2, 0, 8, -1, 4, 9, -6, 12, -5, 3, 0, 6, -8, 10, 11, -9,
                 0, 7, -4, 14, 2, -3, 5, 6, -1, 13, 4, 7, 9, -2, 6, 1, -7, 11, 3, -5,
                 0, 8, -10, 7, 9, 3, -4, 12, -6, 2};
//Робив з випадковими значеннями бо введення 110 цисел забере багато часу
    int y[60] = {5, -3, 4, 0, 7, -1, 3, 9, -2, 8, 6, -4, 11, 12, 15, -10, 2, -5, 3, 1,
                 -8, 4, 0, 7, -2, 6, -9, 1, 10, 3, 7, 0, 5, -6, 11, 8, -3, 4, -1, 6,
                 9, 5, -7, 10, 8, 2, -4, 3, 6, -5, 7, -8, 12, -3, 4, 11};

    transform_array(x, 50);
    transform_array(y, 60);

    printf("Transformed array x:\n");
    for (int i = 0; i < 50; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");

    printf("Transformed array y:\n");
    for (int i = 0; i < 60; i++) {
        printf("%d ", y[i]);
    }
    printf("\n");

    return 0;
}
