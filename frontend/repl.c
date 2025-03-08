#include "repl.h"
#include "glib.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static bool handle_exits(char *line);

// Runs the interactive repl until the exit.
void run_repl() {
  printf("StoneScript v0.1 \n");
  while (true) {
    char *line = NULL;
    size_t size;
    printf(">>> ");
    if (!getline(&line, &size, stdin)) {
      return;
    }
    char* stripped_line =  g_strstrip(line);
    if (handle_exits(stripped_line)) {
      free(line);
      return;
    }
    printf("%s\n", line);
  }
}

static bool handle_exits(char *line) {
  if (strcmp(line, "exit") == 0) {
    return true;
  } else {
    return false;
  }
}
