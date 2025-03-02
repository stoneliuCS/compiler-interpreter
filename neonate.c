#include <stdio.h>
#include <stdint.h>

extern int64_t_our_code_starts_here() asm("our code starts here.");

int main(int argc, char** argv) {
  int64_t result = our_code_starts_here();
  printf("%ld\n", result);
  return 0;
}
