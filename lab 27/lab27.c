#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

bool isMatchingPair(char open, char close) {
    return (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool areBracketsBalanced(const char* expr) {
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == '}' || ch == ']') {
            char last = pop();
            if (!isMatchingPair(last, ch)) {
                return false;
            }
        }
    }
    return top == -1;
}

int main() {
    char expression[100];
    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = '\0';

    if (areBracketsBalanced(expression)) {
        printf("Brackets are balanced.\n");
    } else {
        printf("Brackets are not balanced.\n");
    }

    return 0;
}