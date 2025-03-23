#include "lexer.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

token_list_t *tokenize(const char *source) {
  for (int i = 0; i < strlen(source); i++) {
    char c = source[i];
    printf("%c", c);
  }
  return NULL;
}

void raise_error(Error *err) {
  printf("Encountered an error on line: ");
  printf("%d", err->line_number);
  printf("%s", err->line);
}
