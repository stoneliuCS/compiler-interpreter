#include "lexer.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

static void parser(const char c);
static void handle_alpha_numeric(const char c);

GArray* tokenize(const char* source) {
  for (int i = 0; i < strlen(source); i++) {
    char c = source[i];
    if (c == WHITE_SPACE || c == NEW_LINE) continue; //Skip over any whitespace or new lines.
    parser(c);
  }
  return NULL;
}

static void parser(const char c) {
  switch (c) {
    case SEMICOLON:
      printf("FOUND SEMICOLON");
      break;
    case LEFT_PAREN:
      printf("FOUND LEFT_PAREN");
      break;
    case RIGHT_PAREN:
      printf("FOUND RIGHT_PAREN");
      break;
    case EQ:
      printf("FOUND RIGHT_PAREN");
      break;
    default:
      handle_alpha_numeric(c);
  }
}

static void handle_alpha_numeric(char c) {
  if (isalpha(c)){
    printf("Is Alpha\n");
  } else if (isdigit(c)) {
    printf("is Digit\n");
  }
}
