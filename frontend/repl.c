#include "repl.h"
#include "glib.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"

static bool handle_exits(char *line);

void run_repl() {
  printf("StoneScript v0.1 \n");
  while (true) {
    char *line = NULL;
    size_t size;
    printf(">>> ");
    if (!getline(&line, &size, stdin)) {
      return;
    }
    char* stripped_line = g_strstrip( line); // This is the string modified in place.
    if (handle_exits(stripped_line)) return;
    tokenize(stripped_line);
    free(line);
  }
}

static bool handle_exits(char *line) {
  if (strcmp(line, "exit") == 0) {
    return true;
  } else {
    return false;
  }
}
