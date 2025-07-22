

#include <stddef.h>

#include "../../../src/app/service/service.h"
#include "../../../unity/src/unity.h"
void test_substract() {
  int output = substract_x(10, 20);
  TEST_ASSERT_EQUAL(30, output);
}

void setUp() {}

void tearDown() {}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_substract);

  UNITY_END();

  return 0;
}
