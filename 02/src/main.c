#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <Windows.h>

#include "../../helper/helpers.h"

#define MAX_LINE_LENGTH 1000
#define SAMPLE_SOL "8"

#define RED 12
#define GREEN 13
#define BLUE 14

typedef struct {
    char **tokens;
    int count;
} Tokens;

Tokens split(char *string, char *delimiter) {
    char *token = strtok(string, delimiter);

    char **tokens = malloc(sizeof(char*) * strlen(string));
    int i = 0;
    while( token != NULL ) {
//        printf( " %s\n", token);
        tokens[i++] = token;
        token = strtok(NULL, delimiter);
    }

    Tokens result = {tokens, i};
    return result;
}

char* sol(char* input) {
    int line_count = get_num_lines(input);
    char** lines = read_lines(input, &line_count);
    int seen[1000] = {0};

    unsigned int sumId = 0;

    for (int i = 0; i < line_count; i++) {

        lines[i][strcspn(lines[i], "\n")] = 0;  // Remove trailing newline
        Tokens tokens = split(lines[i], " ,:");

        int r = 0, g = 0, b = 0;
        int check = 0;
        for (int j = 0; j < tokens.count; ++j) {
            char *next = j + 1 < tokens.count ? tokens.tokens[j + 1] : NULL; // Check the index before accessing the next token
            if (next != NULL) {
                int len = strlen(next);
                if (next[len - 1] == ';') {
                    check = 1;
                }

                if (j + 1 == tokens.count - 1) {
                    int len2 = strlen(next);
                    if (len2 > 0) {
                        next[len2 - 1] = '\0';
                    }
                }
                char *colour = strtok(next, ";");
                if (strcmp(colour, "red") == 0) {
                    r += atoi(tokens.tokens[j]);
                } else if (strcmp(colour, "green") == 0) {
                    g += atoi(tokens.tokens[j]);
                } else if (strcmp(colour, "blue") == 0) {
                    b += atoi(tokens.tokens[j]);
                }
            }

            if (check == 1 || j == tokens.count - 1) {
                printf("%d %d %d\n", r, g, b);
                if (r < RED && g < GREEN && b < BLUE && seen[i] == 0) {
//                    printf("AAAAA%s\n", tokens.tokens[1]);
                    sumId += atoi(tokens.tokens[1]);
                    seen[i] = 1;
                } else if ((r > RED || g > GREEN || b > BLUE) && seen[i] == 1) {
//                    printf("DDDDD%s\n", tokens.tokens[1]);
                    sumId -= atoi(tokens.tokens[1]);
                    seen[i] = 2;
                }else if (seen[i] == 0) {
//                    printf("BBBBB%s\n", tokens.tokens[1]);
                        seen[i] = 1;
                } else {
//                    printf("CCCCC%s\n", tokens.tokens[1]);
                }

                r = 0;
                g = 0;
                b = 0;
                check = 0;
            }
        }
    }

    printf("%d\n", sumId);

    char* buffer = malloc(1000 * sizeof(char));
    sprintf(buffer, "%d", sumId);
    return buffer;
}

int main() {
//    sol("./src/sample.txt");
    if (check(sol("./src/sample.txt"), SAMPLE_SOL) == 0) {
        copy_to_clipboard(sol("./src/input.txt"));
    }

    return 1;
}