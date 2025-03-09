#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include <glib.h>
#include "repl.h"
#include "lexer.h"

int main(int argc, char* argv[]) {
  if (argc == 1) {
    run_repl();
  } else if (argc == 2) {
    printf("Compiling...\n");
    const char* filePath = argv[1];
    char* fileContents = readFile(filePath);
    tokenize(fileContents);
    g_free(fileContents);
  } else {
    printf("%s", "Too many arguments given, correct usage <EXECUTABLE_PATH> <FILE_PATH>\n");
    return 1;
  }
  return 0;
}
