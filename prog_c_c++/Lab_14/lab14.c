#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_words_of_length(char *str, int N) {
    int count = 0, length = 0;

    while (*str) {
        if (!isspace(*str)) {
            length++;
        } else {
            if (length == N)
                count++;
            length = 0;
        }
        str++;
    }
    if (length == N)
        count++;

    return count;
}

int main() {
    char line[1000];
    int N;

    printf("Enter a string: ");
    fgets(line, sizeof(line), stdin);

    printf("Enter word length N: ");
    scanf("%d", &N);

    int result = count_words_of_length(line, N);
    printf("Words of length %d: %d\n", N, result);

    return 0;
}
