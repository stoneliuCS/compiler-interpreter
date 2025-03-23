#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include <glib.h>
#include "repl.h"
#include "lexer.h"

// Then entry point into the StoneScript Interpreter Runtime.
int main(int argc, char* argv[]) {
  if (argc > 2) {
    printf("Usage: ss [script] \n");
    return 1;
  } else if (argc == 2) {
    const char* filePath = argv[1];
  } else {
    run_repl();
  }
  return 0;
}
