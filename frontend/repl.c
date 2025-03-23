#include "repl.h"
#include "lexer.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run_repl() {
  printf("StoneScript v0.1 \n");
  while (true) {
    char *line = NULL;
    size_t size;
    printf(">>> ");
    if (!getline(&line, &size, stdin)) {
      return;
    }
    tokenize(line);
    free(line);
  }
}
