#include <stdlib.h>

#ifndef TOKEN_LIST_H 

#define TOKEN_LIST_H

typedef struct token_list token_list_t;

// Creates a new token list with the inital capacity.
token_list_t* create_token_list(const int capacity);

#endif
