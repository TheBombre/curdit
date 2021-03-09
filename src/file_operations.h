#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **read_in_file(FILE *file, int lines);
void handle_null_file(FILE *file);
int count_lines(FILE *file);
FILE *open_file(char *filename);
void print_data(char **file_data, int lines);
void check_file_errors(FILE *file);
