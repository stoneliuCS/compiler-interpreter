// The following file gives abstractions for file operations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

int readFile(const char* filePath) {

  FILE *file_ptr;
  char ch;
  file_ptr = fopen(filePath, "r");

  if (NULL == file_ptr) {
    printf("file can't be opened \n");
    return EXIT_FAILURE;
  }

  while ((ch = fgetc(file_ptr)) != EOF) {

  }
}
