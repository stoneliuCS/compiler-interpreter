#include "lexer.h"
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// A Token Context is Structured Data
// It holds
// A starting index
// A Current index
// The current line number
// The current source program.
typedef struct token_ctx {
  int start;
  int current;
  int line;
  const char* source;
} token_ctx;

static void scanToken(token_ctx ctx, const char c);
static void addToken(token_ctx ctx, TokenType token_type);
static bool isAtEnd(token_ctx ctx);
static bool match(token_ctx ctx, const char expected_next_char);

token_list_t *tokenize(const char *source) {
  token_ctx ctx = {0, 0, 1, source};
  for (int i = 0; i < strlen(source); i++) {
    const char c = source[i];
    ctx.current = ctx.start;
    scanToken(ctx, c);
  }
  return NULL;
}

// Given the context of the tokens, checks whether or not we have reached the end of the 
// source program.
static bool isAtEnd(token_ctx ctx) { return ctx.current >= strlen(ctx.source); }

static bool match(token_ctx ctx, const char expected_next_char) {
  if (isAtEnd(ctx)) {
    return false;
  } else if (ctx.source[ctx.current] != expected_next_char) {
    return false;
  } else {
    ctx.current = ctx.current + 1;
    return true;
  }
}

static void scanToken(token_ctx ctx, const char c) {
  switch (c) {
  case ('('):
    addToken(ctx, LEFT_PAREN);
  case (')'):
    addToken(ctx, RIGHT_PAREN);
  case ('{'):
    addToken(ctx, RIGHT_BRACE);
  case ('}'):
    addToken(ctx, LEFT_BRACE);
  case (','):
    addToken(ctx, COMMA);
  case ('.'):
    addToken(ctx, DOT);
  case ('-'):
    addToken(ctx, MINUS);
  case ('+'):
    addToken(ctx, PLUS);
  case ';':
    addToken(ctx, SEMICOLON);
  case '*':
    addToken(ctx, STAR);
  case '!':
    addToken(ctx, match(ctx, '=') ? NOT_BANG : BANG);
  case '<':
    addToken(ctx, match(ctx, '=') ? LESS_THAN_OR_EQUAL : LESS_THAN);
  case '>':
    addToken(ctx, match(ctx, '=') ? GREATER_THAN_OR_EQUAL : GREATER_THAN);
  default:
    raise_error(ctx.line, "Unexpected Character.");
  }
}

static void addToken(token_ctx ctx, TokenType token_type) {
}

void raise_error(const int line, const char *msg) {
  printf("Encountered an error on line: ");
  printf("%d", line);
  printf("%s", msg);
}
