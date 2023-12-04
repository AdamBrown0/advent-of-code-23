#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <regex.h>

#include "string_helper.h"

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

char* concatenate_strings(char *str1, char *str2) {
    char *result = (char*)malloc(strlen(str1) + strlen(str2) + 1);
    if (!result) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    strcpy(result, str1);
    strcat(result, str2);

    return result;
}

char* regex_match(char *str, char *pattern) {
    regex_t regex;
    int reti;
    char msgbuf[100];

    // Compile regex
    reti = regcomp(&regex, pattern, 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(EXIT_FAILURE);
    }

    // Execute regex
    reti = regexec(&regex, str, 0, NULL, 0);
    if (!reti) {
        printf("Match\n");
    } else if (reti == REG_NOMATCH) {
        printf("No match\n");
    } else {
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        exit(EXIT_FAILURE);
    }

    // Free memory
    regfree(&regex);

    return str;
}

char** tokenize(char *str, char *delim) {
    char **tokens = malloc(sizeof(char*) * 100);
    char *token = strtok(str, delim);
    int i = 0;

    while (token != NULL) {
        tokens[i] = token;
        token = strtok(NULL, delim);
        i++;
    }

    tokens[i] = NULL;
    return tokens;
}