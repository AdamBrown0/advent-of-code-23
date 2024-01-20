#include "file_helper.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

/// read input from file
/// \param filename
/// \param buffer output from file
/// \param buffer_size
/// \return success: 0, fail: -1
void file_read_input(char *filename, char *buffer, int buffer_size) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: file %s not found\n", filename);
        exit(EXIT_FAILURE);
    }
    fgets(buffer, buffer_size, fp);
    fclose(fp);
}

char** read_lines(char* filename, int* num_lines) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: file %s not found\n", filename);
        return NULL;
    }

    char** lines = malloc(sizeof(char*));
    char line[MAX_LINE_LENGTH];
    *num_lines = 0;

    while (fgets(line, sizeof(line), fp)) {
        lines[*num_lines] = strdup(line);
        (*num_lines)++;
        lines = realloc(lines, sizeof(char*) * (*num_lines + 1));
        if (lines == NULL) {
            perror("fucked");
            exit(0);
        }
    }

    fclose(fp);
    return lines;
}

int write_output(char *filename, char *output) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: file %s not found\n", filename);
        return -1;
    }

    fprintf(fp, "%s", output);
    fclose(fp);
    return 0;
}

int* read_int(char *filename, int *num_ints) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: file %s not found\n", filename);
        return NULL;
    }

    int *integers = NULL;
    int value;
    *num_ints = 0;

    while (fscanf(fp, "%d", &value) == 1) {
        (*num_ints)++;
        integers = realloc(integers, *num_ints * sizeof(int));
        integers[*num_ints - 1] = value;
    }

    fclose(fp);
    return integers;
}

int append_to_file(char *filename, char *output) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error: file %s not found\n", filename);
        return -1;
    }

    fprintf(fp, "%s", output);
    fclose(fp);
    return 0;
}

int get_num_lines(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: file %s not found\n", filename);
        return -1;
    }

    int num_lines = 0;
    char c;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            num_lines++;
        }
    }

    fclose(fp);
    return num_lines + 1;
}
