/**
 * @file dynamic_array.c
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

int main(int argc, char **argv); 

typedef struct {
    int *arr;
    int size;
} dynamic_array_t;

dynamic_array_t *create_dynamic_array(int size)
{
    dynamic_array_t *dyn_arr = malloc(sizeof(dynamic_array_t));
    dyn_arr->arr = malloc(sizeof(int) * size);
    dyn_arr->size = size;
    return dyn_arr;
}

void destroy_dynamic_array(dynamic_array_t *dyn_arr)
{
    free(dyn_arr->arr);
    free(dyn_arr);
}

void print_dynamic_array(dynamic_array_t *dyn_arr)
{
    for (int i = 0; i < dyn_arr->size; i++)
    {
        printf("dyn_arr[%d] = %d\n", i, dyn_arr->arr[i]);
    }
}

int main(int argc, char **argv)
{
    dynamic_array_t *dyn_arr = create_dynamic_array(10);
    for (int i = 0; i < dyn_arr->size; i++)
    {
        dyn_arr->arr[i] = i;
    }
    print_dynamic_array(dyn_arr);
    destroy_dynamic_array(dyn_arr);
    return 0;
}

