#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <Windows.h>

#include "../../helper/helpers.h"

#define MAX_LINE_LENGTH 1000
#define SAMPLE_SOL "288"

char* sol(char* input) {
    int line_count = get_num_lines(input);
    char** lines = read_lines(input, &line_count);
    if (lines == NULL) {
        perror("fuck");
    }

    int* times = calloc(3, sizeof(int));
    int* dists = (int*) calloc(3, sizeof(int));

    char* time_line = lines[0];
    size_t line_len = strlen(time_line);
    int next_free = 0;
    for (int i = 0; i < line_len; i++) {
        int tmp = 0;
        if (isdigit(time_line[i])) {
            tmp = atoi(&time_line[i++]);
        }
        if (tmp != 0) {
            times[next_free++] = tmp;
        }

    }

    char* dist_line = lines[0];
    line_len = strlen(dist_line);
    next_free = 0;
    for (int i = 0; i < line_len; i++) {
        int tmp = 0;
        if (isdigit(dist_line[i])) {
            tmp = atoi(&dist_line[i++]);
        }
        if (tmp != 0) {
            dists[next_free++] = tmp;
        }

    }

    for (int i = 0; i < 6; ++i) {
        printf("Time: %d\nDist: %d\ni: %d\n----------\n", times[i], dists[i], i);
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