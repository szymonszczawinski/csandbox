#include "pointers.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct Token {
    char *literal;
    int row;
    int collumn;
} token_t;

void display_token(token_t t)
{
    printf("token: %s, %d, %d\n", t.literal, t.row, t.collumn);
}

void run_update_pointer_pointer();
void allocate_int(int **pp, int value);
void run_copy_pointers_array();
token_t **create_token_pointer_array(token_t *tokens, size_t count);

void run_pointers()
{
    run_update_pointer_pointer();
    run_copy_pointers_array();
}

void run_copy_pointers_array()
{
    token_t t1 = {.literal = "token a", .row = 1, .collumn = 1};
    token_t t2 = {.literal = "token b", .row = 2, .collumn = 3};

    token_t tokens[2] = {t1, t2};

    token_t **new_tokens = create_token_pointer_array(tokens, 2);
    printf("old tokens: \n");
    for (int i = 0; i < 2; i++) {
        display_token(tokens[i]);
    }
    printf("new tokens: \n");
    for (int i = 0; i < 2; i++) {
        display_token(*new_tokens[i]);
    }
}

token_t **create_token_pointer_array(token_t *tokens, size_t count)
{
    token_t **token_pointers = malloc(count * sizeof(token_t *));
    for (size_t i = 0; i < count; i++) {
        token_t *p = malloc(sizeof(token_t));
        token_pointers[i] = p;
        *p = tokens[i];
    }
    return token_pointers;
}

void run_update_pointer_pointer()
{
    int a = 5;
    int *p = &a;
    allocate_int(&p, 10);
    printf("old value is %d new value is %d\n", a, *p);
}

// assign new value to int**
void allocate_int(int **pp, int value)
{
    int *new_p = malloc(sizeof(int));
    *new_p = value;
    *pp = new_p;
}
