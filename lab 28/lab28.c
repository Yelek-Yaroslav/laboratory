#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

#define ESC 27
#define INITIAL_CAPACITY 10
#define MAX_DIGITS 20

int main() {
    int *queue = malloc(INITIAL_CAPACITY * sizeof(int));
    if (!queue) {
        perror("Memory allocation error");
        return 1;
    }

    int size = 0;
    int capacity = INITIAL_CAPACITY;
    char input[MAX_DIGITS + 1];
    int ch, index;

    printf("Enter integers. Press Esc at any time to stop input.\n");

    while (1) {
        printf("Number %d: ", size + 1);
        index = 0;

        while (1) {
            ch = getch();

            if (ch == ESC) {
                printf("\nInput interrupted.\n");
                goto done;
            } else if (ch == '\r') {
                input[index] = '\0';
                printf("\n");
                break;
            } else if (isdigit(ch) || (ch == '-' && index == 0)) {
                if (index < MAX_DIGITS) {
                    input[index++] = ch;
                    putchar(ch);
                }
            } else if (ch == '\b' && index > 0) {
                index--;
                printf("\b \b");
            }
        }

        int number = atoi(input);

        if (size >= capacity) {
            capacity *= 2;
            int *temp = realloc(queue, capacity * sizeof(int));
            if (!temp) {
                perror("Reallocation error");
                free(queue);
                return 1;
            }
            queue = temp;
        }

        queue[size++] = number;
    }

done:
    if (size == 0) {
        printf("Queue is empty.\n");
    } else {
        int max = queue[0];
        int pos = 0;
        for (int i = 1; i < size; i++) {
            if (queue[i] > max) {
                max = queue[i];
                pos = i;
            }
        }
        printf("\nMaximum element: %d\nPosition in queue: %d\n", max, pos + 1);
    }

    free(queue);
    return 0;
}