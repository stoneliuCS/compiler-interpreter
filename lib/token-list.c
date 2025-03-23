#include "token-list.h"
#include "../frontend/lexer.h"
#include <stdlib.h>
#include <assert.h>

struct token_list {
  Token **tokens;
  unsigned int size;
  unsigned int capacity;
};

token_list_t *create_token_list(const int capacity) {
  size_t size = sizeof(token_list_t);
  token_list_t *ptr = (token_list_t *)malloc(size);
  assert(ptr != NULL);
  ptr->size = 0;
  ptr->capacity = capacity;
  size_t size_of_token = sizeof(Token);
  ptr->tokens = (Token**) malloc(size_of_token * capacity);
  assert(ptr->tokens != NULL);
  return ptr;
}
