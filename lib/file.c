// The following file gives abstractions for file operations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

// reads the file from the given filePath, returning a dynamically sized array.
// The client caller is responsible for freeing the the memory allocated by this function.
GArray* readFile(const char* filePath) {

  FILE *file_ptr;
  GArray* vector = g_array_new(FALSE, FALSE, sizeof(guint));
  char ch;
  file_ptr = fopen(filePath, "r");

  if (NULL == file_ptr) {
    printf("file can't be opened \n");
    return EXIT_FAILURE;
  }

  while ((ch = fgetc(file_ptr)) != EOF) {
    g_array_append_val(vector, ch);
  }

  fclose(file_ptr);

  return vector;

}
