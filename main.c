#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/file.h"

int main(int argc, char* argv[]) {
  if (argc == 1) {
    // Start the REPL
    printf("starting repl...\n");
  } else if (argc == 2) {
    // Assume they have given us a file path, read the file path.
    printf("Compiling\n");
  } else {
    printf("%s", "Too many arguments given, correct usage ./a.out <FILE_PATH>\n");
    return 1;
  }
  return 0;
}
