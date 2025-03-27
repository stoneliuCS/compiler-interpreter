#include "./token.h"
#include <stdlib.h>

Token *create_token(TokenType type, char *lexeme, void *literal, int line) {
  Token *token = malloc(sizeof(Token));
  token->type = type;
  token->lexeme = lexeme;
  token->line = line;
  token->literal = literal;
  return token;
}
