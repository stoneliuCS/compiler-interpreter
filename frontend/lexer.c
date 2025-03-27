#include "lexer.h"
#include <assert.h>
#include <glib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// A Token Context is Structured Data
// It holds
// A starting index
// A Current index
// The current line number
// The current source program.
// The current running list of tokens.
// A flag to see if the source program has errors.
typedef struct token_ctx {
  int start;
  int current;
  int line;
  const char *source;
  token_list_t *tokens;
  bool error;
} token_ctx;

// Scans for the next token, consuming it.
static void scan_token(token_ctx ctx);
// Adds that token to the running context.
static void add_token(token_ctx ctx, TokenType token_type);
// Consumes the next token from the context and returns it.
static char advance(token_ctx ctx);
// Given the context of the tokens, checks whether or not we have reached the
// end of the source program.
static bool is_end(token_ctx ctx);
// Peeks but does not consumes the next token.
static char peek(token_ctx ctx);
// Gets the current character from the source program.
static char current(token_ctx ctx);
// Does a conditional advance if the expected next char matches.
static bool match(token_ctx ctx, const char expected_next_char);
// Given that the next element is <, attempts to match either <, <-, or <=
static void match_on_left_carrot(token_ctx ctx);
// Increments the line counter in the context;
static void increment_line(token_ctx ctx);
// Create the token table.
static GHashTable *construct_token_table();

static void reset(token_ctx ctx) { ctx.start = ctx.current; }

static char current(token_ctx ctx) { return ctx.source[ctx.current]; }

static char advance(token_ctx ctx) { return ctx.source[ctx.current++]; }

static char peek(token_ctx ctx) {
  return is_end(ctx) ? '\0' : ctx.source[ctx.current + 1];
}

static void increment_line(token_ctx ctx) { ctx.line = ctx.line + 1; }

static bool is_end(token_ctx ctx) { return ctx.current >= strlen(ctx.source); }

static bool match(token_ctx ctx, const char expected_next_char) {
  if (is_end(ctx)) {
    return false;
  } else if (ctx.source[ctx.current] != expected_next_char) {
    return false;
  } else {
    ctx.current = ctx.current + 1;
    return true;
  }
}

static void match_on_left_carrot(token_ctx ctx) {
  if (match(ctx, '=')) {
    add_token(ctx, LESS_THAN_OR_EQUAL);
  } else if (match(ctx, '-')) {
    add_token(ctx, ASSIGNMENT);
  } else {
    add_token(ctx, LESS_THAN);
  }
}

static void scan_token(token_ctx ctx) {
  char c = advance(ctx);
  switch (c) {
  case ' ':
    break;
  case '\r':
    break;
  case '\t':
    break;
  case '\n':
    increment_line(ctx);
  case ('('):
    add_token(ctx, LEFT_PAREN);
  case (')'):
    add_token(ctx, RIGHT_PAREN);
  case ('{'):
    add_token(ctx, RIGHT_BRACE);
  case ('}'):
    add_token(ctx, LEFT_BRACE);
  case (','):
    add_token(ctx, COMMA);
  case ('.'):
    add_token(ctx, DOT);
  case ('-'):
    add_token(ctx, MINUS);
  case ('+'):
    add_token(ctx, PLUS);
  case ';':
    add_token(ctx, SEMICOLON);
  case '*':
    add_token(ctx, STAR);
  case '!':
    add_token(ctx, match(ctx, '=') ? NOT_EQUAL : BANG);
  case '<':
    match_on_left_carrot(ctx);
  case '>':
    add_token(ctx, match(ctx, '=') ? GREATER_THAN_OR_EQUAL : GREATER_THAN);
  case '=':
    add_token(ctx, match(ctx, '=') ? EQUAL_EQUAL : EQUAL);
  default:
    raise_error(ctx, "Unexpected Character.");
  }
}

static void add_token(token_ctx ctx, TokenType token_type) {}

token_list_t *tokenize(const char *source) {
  token_ctx ctx = {0, 0, 1, source, create_token_list(10), false};
  while (!is_end(ctx) && !ctx.error) {
    reset(ctx);
    scan_token(ctx);
  }
  return ctx.tokens;
}

void raise_error(token_ctx ctx, const char *msg) {
  printf("Encountered an error on line: ");
  printf("%d", ctx.line);
  printf("%s", msg);
  ctx.error = true;
}
