#include <stdlib.h>
#include "../frontend/token.h"
#ifndef TOKEN_LIST_H 

#define TOKEN_LIST_H

typedef struct token_list token_list_t;

#define CAPACITY_INCREASE_RATE 2;

// Creates a new token list with the inital capacity.
token_list_t* create_token_list(const int capacity);

// Appends that token to the back of that token_list.
void append_to_token_list(token_list_t* list, Token token);

// Frees all resources from the given token list.
void free_token_list(token_list_t* list);

// Gets the token list capacity.
int get_token_list_capacity(token_list_t* list);

// Gets the token_list current size
int get_token_current_size(token_list_t* list);

#endif
