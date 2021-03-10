/**
 * @file
 * @brief Functions that manipulate the text area
 * */
#include "../include/main.h"

/**
 * Rendering text for the user to see
 * @param text_area window in which the text is displayed
 * @param file_data 2D array containing file text
 * @param lines number of lines in file
 * */
void display_text(WINDOW *text_area, char **file_data, int lines) {
  for (int i = 0; i < lines; i++) {
    wprintw(text_area, file_data[i]);
  }
}

/**
 * Receives keypress and decides actions to perform
 * @param character the key pressed by the user
 * @param mode from the MODES enum
 * */
void handle_keypress(WINDOW *text_area, char character, enum Mode mode) {
  if (character == CONTROL_KEY('q')) {
    // TODO: complete with the handle_user_exit here
    exit(EXIT_SUCCESS);
  } else if (mode == NORMAL) {
    // Get current cursor position
    int row, column;
    getyx(text_area, row, column);

    switch (character) {
    case 'h':
      wmove(text_area, row, column - 1);
      break;
    case 'j':
      wmove(text_area, row + 1, column);
      break;
    case 'k':
      wmove(text_area, row - 1, column);
      break;
    case 'l':
      wmove(text_area, row, column + 1);
      break;
    case 's':
      // TODO:implement save functionality
      break;
    case 'o':
      // TODO: implement opening files while editing another
      break;
    case 'i':
      change_mode_to(INSERT);
      break;
    case 'r':
      // TODO: ability to redo change
      break;
    case 'u':
      // TODO: ability to undo change
      break;
    default:
      // TODO: maybe saving as a change?
      break;
    }
    wrefresh(text_area);
  } else if (mode == INSERT) {
    if (CONTROL_KEY('n') == character) {
      change_mode_to(NORMAL);
    }
  }
}
