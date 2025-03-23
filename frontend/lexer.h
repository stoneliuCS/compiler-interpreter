#include <glib.h>
#include "./token.h"
#include "../lib/token-list.h"

#ifndef LEXER_H 

#define LEXER_H

// Tokenizes the source code into a token_list. 
token_list_t* tokenize(const char* source);

// Raises an error during runtime.
void raise_error(const int line, const char* msg);

#endif
