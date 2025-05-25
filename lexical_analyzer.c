#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keywords[10][10] = {"int", "float", "if", "else", "while", "for", "return", "void", "char", "double"};
char operators[] = "+-*/=><";

int isKeyword(char *word) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char ch) {
    for (int i = 0; i < strlen(operators); i++) {
        if (ch == operators[i])
            return 1;
    }
    return 0;
}

int main() {
    FILE *file;
    char ch, word[20];
    int i;

    file = fopen("input.txt", "r");

    if (!file) {
        printf("Cannot open input file.\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (isalpha(ch)) {
            i = 0;
            while (isalnum(ch)) {
                word[i++] = ch;
                ch = fgetc(file);
            }
            word[i] = '\0';
            fseek(file, -1, SEEK_CUR); // move one char back

            if (isKeyword(word))
                printf("%s --> Keyword\n", word);
            else
                printf("%s --> Identifier\n", word);
        } else if (isOperator(ch)) {
            printf("%c --> Operator\n", ch);
        }
    }

    fclose(file);
    return 0;
}
