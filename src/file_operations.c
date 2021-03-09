/**
 * @file
 * @brief Functions relating to files
 * */
#include "../include/file_operations.h"

/**
 * Reads in the data from a specified file stream
 * @param file pointer to a file stream
 * @param lines number of lines in file
 * @return 2D array of file data
 * */
char **read_in_file(FILE *file, int lines) {
  handle_null_file(file);

  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  int counter = 0;
  char **file_data = malloc(lines * sizeof(char *));

  while ((read = getline(&line, &len, file)) != -1) {
    file_data[counter] = malloc(read * sizeof(char));
    strcpy(file_data[counter], line);
    counter++;
  }

  check_file_errors(file);
  fclose(file);
  if (line)
    free(line);
  return file_data;
}

/**
 * Checks if file is null, if so exits
 * @param file a pointer to a file stream
 * */
void handle_null_file(FILE *file) {
  if (!file) {
    perror("Failed to open file");
    exit(EXIT_FAILURE);
  }
}

/**
 * Counts the number of lines in a file
 * @param file a pointer to a file stream
 * @return number of lines in file
 * */
int count_lines(FILE *file) {
  handle_null_file(file);
  int count = 0;

  for (char c = getc(file); c != EOF; c = getc(file))
    if (c == '\n') // Increment count if this character is newline
      count = count + 1;

  check_file_errors(file);
  fclose(file);

  return count;
}

/**
 * Attempts to open a specified file
 * @param filename path to file (relative or absolute)
 * @return a pointer to a file stream
 * */
FILE *open_file(char *filename) {
  FILE *file = fopen(filename, "r");
  handle_null_file(file);

  return file;
}

/**
 * Prints out a 2D array, used to print the file data
 * @param file_data double pointer array for the file data
 * @param lines number of lines in file
 * */
void print_data(char **file_data, int lines) {
  for (int i = 0; i < lines; i++) {
    printf("%s", file_data[i]);
  }
}

/**
 * Checks if a file has any errors, if so exits
 * @param file a pointer to a file stream
 * */
void check_file_errors(FILE *file) {
  if (ferror(file)) {
    printf("Error occured while attempting to read in the file. Ensure to use "
           "UTF-8 characters");
    exit(EXIT_FAILURE);
  }
}
