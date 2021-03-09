/**
 * @file
 * @brief Main execution point of the program
 * */
#include "main.h"
#include "file_operations.h"

static WINDOW *status_window;
static WINDOW *file_window;
static char **file_data;

int main(int argc, char **argv) {
  atexit(clean_up);

  if (argc < 2 || argc > 2) {
    printf("Error: Incorrect usage\n");
    printf("Usage: ./curdit [file]\n");
    printf("Where [file] can be a relative or absolute path to the file\n");
    exit(EXIT_FAILURE);
  }

  // load in file
  int lines = count_lines(open_file(argv[1]));
  file_data = read_in_file(open_file(argv[1]), lines);
  // print_data(file_data, lines);

  // Initialisation functions
  initscr();
  raw();
  noecho();
  keypad(stdscr, true);
  refresh();

  // get screen size
  int rows, columns;
  getmaxyx(stdscr, rows, columns);

  int file_window_rows = 0.92 * rows;
  status_window = newwin(rows - file_window_rows, columns, file_window_rows, 0);
  file_window = newwin(file_window_rows, columns, 0, 0);

  // Setup borders around windows
  wborder(status_window, 0, 0, 0, 0, 0, 0, 0, 0);
  wborder(file_window, 0, 0, 0, 0, 0, 0, 0, 0);

  // Windows titles
  mvwprintw(status_window, 0, columns / 2 - 5, " Status ");
  mvwprintw(file_window, 0, columns / 2 - 5, " main.c ");

  // Update windows
  wrefresh(status_window);
  wrefresh(file_window);

  getch();
  clean_up();
  return EXIT_SUCCESS;
}

/**
 * Deletes all the windows before exiting
 * */
void clean_up() {
  delwin(status_window);
  delwin(file_window);
  endwin();
}
