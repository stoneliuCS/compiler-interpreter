#include "./token-map.h"
#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

// FNV-1a hash implementation.
static uint64_t hash(const char *key);
// Expands the token_map if its at capacity.
static void expand(token_map_t *map);
// Gets the index from the hash implementation.
static int get_index(token_map_t *map, const char *key);
static void token_map_put_impl(token_map_t *map, const char *key,
                                       Token *val);

typedef struct {
  char *key;
  Token *val;
} token_map_entry_t;

typedef struct token_map {
  token_map_entry_t *entries;
  size_t capacity;
  size_t size;
} token_map_t;

static uint64_t hash(const char *key) {
  uint64_t hash = FNV_OFFSET;
  for (const char *p = key; *p; p++) {
    hash = hash ^ *p;
    hash = hash * FNV_PRIME;
  }
  return hash;
}

static void expand(token_map_t *map) {
  int new_capacity = map->size * 2;
  token_map_entry_t *entries = calloc(new_capacity, sizeof(token_map_entry_t));
  assert(entries != NULL);
  for (int i = 0; i < map->capacity; i++) {
    token_map_entry_t entry = entries[i];
    if (entry.key != NULL) {
      //
    }
  }
  free(map->entries);
  map->entries = entries;
  map->capacity = new_capacity;
}

static int get_index(token_map_t *map, const char *key) {
  uint64_t hash_key = hash(key);
  return hash_key & map->capacity - 1;
}

static void token_map_put_impl(token_map_t *map, const char *key,
                                       Token *val) {
  int index = get_index(map, key);
  while (map->entries->key != NULL) {
    if (strcmp(map->entries[index].key, key) == 0) {
      map->entries[index].val = val;
      return;
    } else {
      index = index >= map->capacity ? 0 : index + 1;
    }
  }
  map->entries[index].key = (char*) key;
  map->entries[index].val = val;
  map->size = map->size + 1;
}

token_map_t *create_token_map() {
  token_map_t *map = malloc(sizeof(token_map_t));
  assert(map != NULL);
  map->capacity = INITIAL_CAPACITY;
  map->size = 0;
  map->entries = calloc(map->capacity, sizeof(token_map_entry_t));
  assert(map->entries != NULL);
  return map;
}

Token *token_map_get(token_map_t *map, const char *key) {
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

void token_map_put(token_map_t *map, const char *key, Token *val) {
  if (map->size >= map->capacity) {
    expand(map);
  }
  token_map_put_impl(map, key, val);
}

void free_token_map(token_map_t *map) {
  for (int i = 0; i < map->capacity; i++) {
    token_map_entry_t entry = map->entries[i];
    free(entry.val);
  }
  free(map->entries);
  free(map);
}

int token_map_size(token_map_t *map) {
  assert(map != NULL);
  return map->size;
}

int token_map_capacity(token_map_t *map) {
  assert(map != NULL);
  return map->capacity;
}
