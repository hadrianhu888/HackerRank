/**
 * @file vector.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

typedef struct {
    int *arr;
    int size;
    int capacity;
} vector_t;

vector_t *create_vector(int capacity)
{
    vector_t *vec = malloc(sizeof(vector_t));
    vec->arr = malloc(sizeof(int) * capacity);
    vec->size = 0;
    vec->capacity = capacity;
    return vec;
}

void destroy_vector(vector_t *vec)
{
    free(vec->arr);
    free(vec);
}

void print_vector(vector_t *vec)
{
    for (int i = 0; i < vec->size; i++)
    {
        printf("vec[%d] = %d\n", i, vec->arr[i]);
    }
}

void push_back(vector_t *vec, int value)
{
    if (vec->size == vec->capacity)
    {
        vec->capacity *= 2;
        vec->arr = realloc(vec->arr, sizeof(int) * vec->capacity);
    }
    vec->arr[vec->size++] = value;
}

void pop_back(vector_t *vec)
{
    if (vec->size > 0)
    {
        vec->size--;
    }
}

int main(int argc, char **argv)
{
    vector_t *vec = create_vector(10);
    for (int i = 0; i < 10; i++)
    {
        push_back(vec, i);
    }
    print_vector(vec);
    pop_back(vec);
    print_vector(vec);
    destroy_vector(vec);
    return 0;
}

// Compare this snippet from vector.c: