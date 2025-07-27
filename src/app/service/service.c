#include "service.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
} Person;

Person createPerson(const char *name, int age)
{
    Person p;
    p.age = age;
    strcpy(p.name, name);
    return p;
}
Person *createPersonOnHeap(const char *name, int age)
{
    Person *p = malloc(sizeof(Person));
    if (p == NULL) {
        perror("malloc failed");
        return NULL;
    }
    p->name = malloc(strlen(name) + 1);
    strcpy(p->name, name);
    p->age = age;
    return p;
}
void run_service()
{
    // Person p1 = createPerson("Szymon", 41);
    Person *p2 = createPersonOnHeap("Piotr", 37);

    // printf("Person 1 %s %d\n", p1.name, p1.age);
    printf("Person 2 %s %d\n", p2->name, p2->age);
}
int substract_x(int a, int b) { return a - b; }
