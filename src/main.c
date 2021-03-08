#include "main.h"

int main() {
  // Initialisation functions
  initscr();
  raw();
  noecho();
  keypad(stdscr, true);

  // get screen size
  int rows, columns;
  getmaxyx(stdscr, rows, columns);

  // Window* file_window = newwin()
  int num = 0.9 * 41;

  printw("Hello world: rows: %d, columns: %d\n", rows, columns);
  printw("Number: %d", num);
  refresh();
  getch();
  endwin();
  return EXIT_SUCCESS;
}
