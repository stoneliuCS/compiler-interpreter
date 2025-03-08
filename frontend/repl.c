#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "repl.h"

static bool handle_exits(const char* line);

// Runs the interactive repl until the exit.
void runRepl() {
  printf("StoneScript v0.1 \n");
  while (true) {
    char* line = NULL;
    size_t size;
    printf("> ");
    if (getline(&line, &size, stdin)) {
      if (handle_exits(line)) {
        free(line);
        return;
      }
      printf("%s", line);
    }
  }
}

static bool handle_exits(const char* line) {
  if (strcmp(line, "exit")) {
    return true;
  } else {
    return false;
  }
}
