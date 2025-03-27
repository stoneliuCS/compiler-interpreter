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

const char *match_token_type(TokenType type) {
  switch (type) {
  case LEFT_PAREN:
    return "(";
  case RIGHT_PAREN:
    return ")";
  case LEFT_BRACE:
    return "{";
  case RIGHT_BRACE:
    return "}";
  case COMMA:
    return ",";
  case DOT:
    return ".";
  case MINUS:
    return "-";
  case PLUS:
    return "+";
  case SEMICOLON:
    return ";";
  case SLASH:
    return "/";
  case STAR:
    return "*";
  case BANG:
    return "!";
  case NOT_EQUAL:
    return "";
  case EQUAL:
    return "";
  case EQUAL_EQUAL:
    return "";
  case LESS_THAN:
    return "";
  case GREATER_THAN:
    return "";
  case LESS_THAN_OR_EQUAL:
    return "";
  case GREATER_THAN_OR_EQUAL:
    return "";
  case ASSIGNMENT:
    return "";
  case AND:
    return "";
  case CLASS:
    return "";
  case ELSE:
    return "";
  case FALSE:
    return "";
  default:
    return NULL;
  }
}
