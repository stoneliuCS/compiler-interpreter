#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "repl.h"
// Runs the interactive repl until the user stops..
void runRepl() {
  while (true) {
    printf("StoneScript v0.1 \n");
    char* line = NULL;
    size_t size;
    if (getline(&line, &size, stdin)) {
      printf("> ");
    }
  }
}
