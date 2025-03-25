#include "./token-map.h"
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include <sys/errno.h>

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

static uint64_t hash(const char* key);

typedef struct {
  char* key;
  Token* val;
} token_map_entry_t;

typedef struct token_map {
  token_map_entry_t* entries;
  size_t capacity;
  size_t size;
} token_map_t;

token_map_t* create_token_map() {
  token_map_t* map = malloc(sizeof(token_map_t));
  assert(map != NULL);
  map->capacity = INITIAL_CAPACITY;
  map->size = 0;
  map->entries = calloc(map->capacity, sizeof(token_map_entry_t));
  assert(map->entries != NULL);
  return map;
}

Token* token_map_get(token_map_t* map, const char* key) {
  uint64_t hash_key = hash(key);
  int index = hash_key & map->capacity - 1;
  while (map->entries[index].key != NULL) {
    if (strcmp(key, map->entries[index].key) == 0) {
      return map->entries[index].val;
    } else {
      index = index >= map->capacity ? 0 : index + 1;
    } 
  }
  return NULL; 
}

//FNV-1a hash implementation.
static uint64_t hash(const char* key) {
  uint64_t hash = FNV_OFFSET;
  for (const char* p = key; *p; p++) {
    hash = hash ^ *p;
    hash = hash * FNV_PRIME;
  }
  return hash;
}

void free_token_map(token_map_t* map) {
  for (int i = 0; i < map->capacity; i++) {
    token_map_entry_t entry = map->entries[i];
    free(entry.key);
  }
  free(map->entries);
  free(map);
}

int token_map_size(token_map_t* map) {
  assert(map != NULL);
  return map->size;
}

int token_map_capacity(token_map_t* map) {
  assert(map != NULL);
  return map->capacity;
}
