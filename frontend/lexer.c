#include "lexer.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct token_ctx {
  int start;
  int current;
  int line;
};

static void scanToken(struct token_ctx ctx, char c);
static void addToken(TokenType token_type);

token_list_t *tokenize(const char *source) {
  struct token_ctx ctx = {0, 0, 1};
  for (int i = 0; i < strlen(source); i++) {
    const char c = source[i];
    ctx.current = ctx.start;
    scanToken(ctx, c);
  }
  return NULL;
}

static void scanToken(struct token_ctx ctx, const char c) {
  switch (c) {
  case ('('):
    addToken(LEFT_PAREN);
  case (')'):
    addToken(RIGHT_PAREN);
  case ('{'):
    addToken(RIGHT_BRACE);
  case ('}'):
    addToken(LEFT_BRACE);
  case (','):
    addToken(COMMA);
  case ('.'):
    addToken(DOT);
  case ('-'):
    addToken(MINUS);
  case ('+'):
    addToken(PLUS);
  case ';':
    addToken(SEMICOLON);
  case '*':
    addToken(STAR);
  default:
    raise_error(ctx.line, "Unexpected Character.");
  }
}

static void addToken(TokenType token_type) {}

void raise_error(const int line, const char *msg) {
  printf("Encountered an error on line: ");
  printf("%d", line);
  printf("%s", msg);
}
