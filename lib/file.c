// The following file gives abstractions for file operations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "file.h"

// Reads the file from the given filePath, returning a dynamically sized array.
// The client caller is responsible for freeing the the memory allocated by this function.
gchar* readFile(const char* filePath) {

  gchar* contents = NULL;
  gsize length = 0;

  gboolean success = g_file_get_contents(filePath, &contents, &length, NULL);

  if (success) {
    return contents;
  } else {
    return NULL;
  }

}
