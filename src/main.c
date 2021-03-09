/**
 * @file
 * @brief Main execution point of the program
 * */
#include "main.h"

static WINDOW *status_window;
static WINDOW *file_window;

int main() {
  // Initialisation functions
  atexit(clean_up);
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
