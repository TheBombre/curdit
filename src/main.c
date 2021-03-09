/**
 * @file
 * @brief Done so doxygen generates documentation for functions in this file
 * */
#include "main.h"

// TODO: Ensure to check which functions return errors and handle these
// appropriately
// TODO: handle atexit method
int main() {
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
  WINDOW *status_window =
      newwin(rows - file_window_rows, columns, file_window_rows, 0);
  WINDOW *file_window = newwin(file_window_rows, columns, 0, 0);

  if (wborder(status_window, 0, 0, 0, 0, 0, 0, 0, 0) == ERR ||
      wborder(file_window, 0, 0, 0, 0, 0, 0, 0, 0) == ERR) {
    printf("Error occurred!");

    exit(EXIT_FAILURE);
  }
  // wmove(file_window,1,1);
  // wmove(status_window, 1, 1);
  wborder(status_window, 0, 0, 0, 0, 0, 0, 0, 0);
  mvwprintw(status_window, 0, columns / 2 - 5, " Status ");
  mvwprintw(file_window, 0, columns / 2 - 5, " main.c ");
  wrefresh(status_window);
  wrefresh(file_window);
  getch();
  endwin();
  return EXIT_SUCCESS;
}
