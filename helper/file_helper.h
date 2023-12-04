#ifndef ADVENT_OF_CODE_23_FILE_HELPER_H
#define ADVENT_OF_CODE_23_FILE_HELPER_H

void file_read_input(char *filename, char *buffer, int buffer_size);
char** read_lines(char *filename, int *num_lines);
int write_output(char *filename, char *output);
int* read_int(char *filename, int *num_ints);
int append_to_file(char *filename, char *output);
int get_num_lines(char *filename);

#endif //ADVENT_OF_CODE_23_FILE_HELPER_H
