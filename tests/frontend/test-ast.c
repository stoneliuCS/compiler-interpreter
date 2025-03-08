#include <CUnit/CUnit.h>
#include <CUnit/Automated.h>

static void test_simple_pass1(void) {
    CU_ASSERT_FATAL(1 == 1);
}

int main() {
  // Intialize a registry.
  CU_initialize_registry();
}
