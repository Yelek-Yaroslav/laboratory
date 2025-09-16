#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

enum {
    LEFT_BR = 257, RIGHT_BR, IFL, THENL, WHILEL, DOL, RETRL,
    READL, PRITL, INTL, CONSTL, IDEN, NUMB
};

int nst = 0;
int lval, lex;
static char nch = '\n';

FILE *PF, *padres;

void get(void);
void number(void);
void word(void);
char *add(char *nm);

char TNM[400];
char *ptn = TNM;

int main(int argc, char *argv[]) {
    PF = fopen("c:\\games\\var2.s", "r");
    padres = fopen("getrez.dan", "w");
    if (!PF) {
        puts("File var2.s isn't open");
        return 1;
    }
    nch = getc(PF);
    get();
    fclose(PF);
    fclose(padres);
    return 0;
}

void get() {
    while (nch != EOF) {
        while (isspace(nch)) {
            if (nch == '\n') nst++;
            nch = getc(PF);
        }
        if (isdigit(nch)) {
            number();
        } else if (isalpha(nch)) {
            word();
        } else if (nch == '{') {
            lex = LEFT_BR;
            nch = getc(PF);
        } else if (nch == '}') {
            lex = RIGHT_BR;
            nch = getc(PF);
        } else if (nch == '(' || nch == ')' || nch == ',' || nch == ';' || nch == '=' ||
                   nch == '+' || nch == '-' || nch == '*' || nch == '/' || nch == '%') {
            lex = nch;
            nch = getc(PF);
        } else {
            if (nch == EOF) {
                lex = EOF;
            } else {
                printf("Invalid symbol: %c\n", nch);
                nch = getc(PF);
            }
        }
    }
    lex = EOF;
}

void number() {
    for (lval = 0; isdigit(nch); nch = getc(PF))
        lval = lval * 10 + nch - '0';
    lex = NUMB;
}

void word() {
    static int cdl[] = {IFL, THENL, WHILEL, DOL, RETRL, READL, PRITL, INTL, CONSTL};
    static char *serv[] = {
        "if", "then", "while", "do", "return",
        "read", "print", "int", "const"
    };
    int i;
    char tx[40], *p;
    for (p = tx; isdigit(nch) || isalpha(nch); nch = getc(PF))
        *(p++) = nch;
    *p = '\0';
    for (i = 0; i < 9; i++) {
        if (strcmp(tx, serv[i]) == 0) {
            lex = cdl[i];
            return;
        }
    }
    lex = IDEN;
    lval = (int) add(tx);
    printf("Address for %s = %p\n", tx, (void *) lval);
    fprintf(padres, "Address for %s = %p\n", tx, (void *) lval);
}

char *add(char *nm) {
    char *p;
    for (p = TNM; p < ptn; p += strlen(p) + 1)
        if (strcmp(p, nm) == 0)
            return p;
    if ((ptn += strlen(nm) + 1) > TNM + 400) {
        puts("Overload of TNM");
        exit(0);
    }
    return strcpy(p, nm);
}
