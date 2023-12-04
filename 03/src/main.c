#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../../helper/helpers.h"

#define MAX_LINE_LENGTH 1000
#define SAMPLE_SOL "8"


// loop through lines
// loop through each line, if digit check if not a period or number around
// if symbol keep track to add to total

bool is_element_in_array(const char* val, char** arr, size_t n) {
    for(size_t i = 0; i < n; i++) {
        if(arr[i] == val)
            return true;
    }
    return false;
}

char* sol(char* input) {
    int num_lines = get_num_lines(input);
    char** lines = read_lines(input, &num_lines);

    for (int i = 0; i < num_lines; ++i) {
        char* line = lines[i];
        // loop through line
        for (int j = 0; j < strlen(line); ++j) {
            char cur = line[j];
//            printf("%c\n", cur);
            int num = 0;
            bool has_symbol = false;
            // check if digit // change this to a while(isdigit(cur) != 0) loop to get the full number
            if (isdigit(cur) != 0) { // if digit, we can check for symbol, and add to tracker
                num = num * 10 + atoi(&cur);
                // check if first line
                if (i == 0) {
                    char* next_line = lines[i + 1];
                    if (j == 0) { // check if first character
                        // xxx
                        // xco
                        // xoo
                        if ( (isdigit(next_line[0]) == 0 && strcmp(&next_line[0], ".") != 0) || (isdigit(next_line[1]) == 0 && strcmp(&next_line[1], ".") != 0) || (isdigit(line[1]) == 0 && strcmp(&line[1], ".") != 0) ) { // if not (number, or period)
                            // this should be a symbol
                            has_symbol = true;
                            printf("has: %c\n", cur);
                            printf("%c\n%c\n%c\n", next_line[0], next_line[1], line[1]);
                        }

                    } else if (j == strlen(line) - 1) { // check if last character
                        // xxx
                        // ocx
                        // oox
                        if ( isdigit(line[j - 1]) == 0 || strcmp(&line[j - 1], ".") != 0 || isdigit(next_line[j]) == 0 || strcmp(&next_line[j], ".") != 0 || isdigit(next_line[j - 1]) == 0 || strcmp(&next_line[j - 1], ".") != 0 ) {
                            has_symbol = true;
                            printf("has last\n");
                        }

                    } else { // if not, we can go left and right
                        // xxx
                        // oco
                        // ooo

                    }
                } else if (i == num_lines - 1) { // check if last line

                } else { // if not, we can go above and below

                }

            }

        }


    }
    
    
    return "buffer";
}

int main() {
    sol("./src/sample.txt");
//    if (check(sol("./src/sample.txt"), SAMPLE_SOL) == 0) {
//        copy_to_clipboard(sol("./src/input.txt"));
//    }

    return 1;
}