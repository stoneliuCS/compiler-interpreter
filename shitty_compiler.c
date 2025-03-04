#include <stdio.h>

struct int_literal {
  int value;
};

void compile_int_literal(struct int_literal* l) {
  printf("mov $%d, %%rax\n", l->value);
}

int main(int argc, char* argv[]) {

  struct int_literal val = {
    .value = 3
  };

  compile_int_literal(&val);

  return 1;
}
