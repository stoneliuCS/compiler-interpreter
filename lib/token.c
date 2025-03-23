#include <stdlib.h>
#include "../frontend/lexer.h"
#include <assert.h>

struct token_list {
  Token **tokens;
  unsigned int size;
  unsigned int capacity;
};

// Dynamically increases the size of that list.
static void increase_size(token_list_t* list) {
  list->capacity = list->capacity * CAPACITY_INCREASE_RATE;
  list->tokens = realloc(list->tokens,  list->capacity * sizeof(Token));
  assert(list->tokens != NULL);
}

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

void append(token_list_t* list, Token* token) {
  assert(list != NULL);
  assert(token != NULL);
  if (list->capacity == list->size) {
    increase_size(list);
  } 
  list->tokens[list->size] = token;
  list->size = list->size + 1;
}

void free_token_list(token_list_t* list) {
  assert(list != NULL);
  for (int i = 0; i < list->capacity; i++) {
    free(list->tokens[i]);
  }
  free(list->tokens);
  free(list);
}

int get_token_list_capacity(token_list_t* list) {
  assert(list != NULL);
  return list->capacity;
}


int get_token_current_size(token_list_t* list) {
  assert(list != NULL);
  return list->size;
}
