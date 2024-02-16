#include "app/calculator/calc.h"
#include "app/hellofunc.h"
#include <stdio.h>

int main() {
  // call a function in another file
  myPrintHelloMake();
  int sum = add(5, 9);
  int diff = substract(6, 2);
  printf("%d\n", sum);
  printf("%d\n", diff);
  return 0;
}
