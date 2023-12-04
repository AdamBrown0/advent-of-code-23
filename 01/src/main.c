#include <stdio.h>
#include <regex.h>
#include <malloc.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int check_char_for_num(char *str, int index) {
    char *numbers[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    char char_plus_two[4];
    strncpy(char_plus_two, &str[index], 3);
    char_plus_two[3] = '\0';

    char char_plus_three[5];
    strncpy(char_plus_three, &str[index], 4);
    char_plus_three[4] = '\0';

    char char_plus_four[6];
    strncpy(char_plus_four, &str[index], 5);
    char_plus_four[5] = '\0';

    for (int i = 0; i < 9; ++i) {
        if (strcmp(char_plus_two, numbers[i]) == 0) {
            return i + 1;
        } else if (strcmp(char_plus_three, numbers[i]) == 0) {
            return i + 1;
        } else if (strcmp(char_plus_four, numbers[i]) == 0) {
            return i + 1;
        }
    }

    return 0;
}

int main() {
    FILE *fp = fopen("/cygdrive/c/Users/adam/Documents/GitHub/advent-of-code-23/01/src/input.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    int sum = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
        int line_len = strlen(line);
        char *new_line = (char *) calloc(line_len + 1, sizeof(char));

        for (int i = 0; i < line_len; i++) {
            char c = line[i];
            if (isdigit(c)) {
                char num_string[2];
                sprintf(num_string, "%c", c);
                strcat(new_line, num_string);
            } else {
                int num = check_char_for_num(line, i);
                if (num != 0) {
                    char num_string[2];
                    sprintf(num_string, "%d", num);
                    strcat(new_line, num_string);
                }
            }
        }

        int num = new_line[0] - '0';
        int last_num = new_line[strlen(new_line) - 1] - '0';
        num *= 10;
        num += last_num;
        sum += num;
    }
    printf("Sum: %d\n", sum);
    return 1;
}