#include "app/calculator/calc.h"
#include "app/hellofunc.h"
#include "app/model/model.c"
#include "app/model/myobject.h"
#include "app/service/service.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void displayArrayInfo(int tablica[]);
typedef struct {
  int id;
  char name[64];
} Person;

Person do_a_thing(Person p) {
  p.id = 100;
  memset(p.name, '0', 64);
  return p;
}

int main() {
  printf("%ld\n", __STDC_VERSION__);
  // call a function in another file
  myPrintHelloMake();

  sayHello();
  int suma = add(5, 9);
  int diff = substract(6, 2);
  printf("%d\n", suma);
  printf("%d\n", diff);
  char characterName[] = "Szymon";
  int age = 90;
  printf("%s - %d\n", characterName, age);

  int diff2 = substract(6, 2);
  float x = 100.12345;

  const float PI = 3.14;

  printf("FLOAT %0.3f\n", x);
  char CCC = toupper('h');
  Student s1 = {"Szymon", 1.1};

  printf("student %s - %f\n", s1.name, s1.gpa);

  enum Day today = Sun;

  printf("today is %d\n", today);

  if (today == Sun || today == Sat) {
    printf("weekend, party time\n");
  }
  int tablica[] = {1, 2, 3, 4, 1, 2, 3, 4, 0, 0};
  displayArrayInfo(tablica);
  object_t *counter = new_obj_integer(5);
  printf("counter: %d\n", counter->data.v_int);
  free(counter);
  Person p = {0};
  p = do_a_thing(p);
  printf("Person p %d, %s\n", p.id, p.name);
  return 0;
}

void displayArrayInfo(int tablica[]) {
  printf("rozmiar = %zu", sizeof(tablica));
}
