#include "s21_validation.h"

int s21_ln_log_validation(char *string) {
  int status = OK;

  if (string) {
    for (size_t i = 0; i < strlen(string); ++i) {
      if (string[i] == 'l') {
        char function[255] = {0};

        while (i < strlen(string)) {
          char *symbol = s21_char_to_string(string[i]);

          strcat(function, symbol);
          free(symbol);
          ++i;

          if (string[i - 1] == '(') break;
        }

        if ((i > 254) ||
            (strcmp(function, "ln(") && strcmp(function, "log("))) {
          status = ERROR;
          break;
        }
      }
    }
  }

  return status;
}