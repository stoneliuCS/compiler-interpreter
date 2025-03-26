#include "../frontend/token.h"
#ifndef TOKEN_MAP_H 

#define TOKEN_MAP_H

typedef struct token_map token_map_t;

#define INITIAL_CAPACITY 16

//Creates an empty token hashmap
token_map_t* create_token_map();

//Frees the token hashmap
void free_token_map(token_map_t* map);

//Gets the token associated with the key
Token* token_map_get(token_map_t* map, const char* key);

//Puts the key and the token value into the hashmap
void token_map_put(token_map_t* map, const char* key, Token* val);

//Gets the current size of the map (Number of entries)
int token_map_size(token_map_t* map);

//Gets the current capacity of the map (Number of entries)
int token_map_capacity(token_map_t* map);
#endif
