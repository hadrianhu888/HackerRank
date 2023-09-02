/**
 * @file embedded_c.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "embedded_c.h"

// Function prototypes

// Function prototypes

void print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}
void print_array2(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}
void print_array3(int arr[static 1], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

// state functions 

void state_function(state_t state)
{
    switch (state)
    {
    case OFF:
        printf("OFF\n");
        break;
    case ON:
        printf("ON\n");
        break;
    case IDLE:
        printf("IDLE\n");
        break;
    case SLEEP:
        printf("SLEEP\n");
        break;
    default:
        printf("Invalid state\n");
        break;
    }
}
state_t state_function2(state_t state)
{
    switch (state)
    {
    case OFF:
        printf("OFF\n");
        break;
    case ON:
        printf("ON\n");
        break;
    case IDLE:
        printf("IDLE\n");
        break;
    case SLEEP:
        printf("SLEEP\n");
        break;
    default:
        printf("Invalid state\n");
        break;
    }
    return state;
}
state_t state_function3(state_t state)
{
    switch (state)
    {
    case OFF:
        printf("OFF\n");
        break;
    case ON:
        printf("ON\n");
        break;
    case IDLE:
        printf("IDLE\n");
        break;
    case SLEEP:
        printf("SLEEP\n");
        break;
    default:
        printf("Invalid state\n");
        break;
    }
    return state;
}

// pointer functions

void pointer_function(int *ptr)
{
    printf("ptr = %p\n", ptr);
}
void pointer_function2(int *ptr)
{
    printf("ptr = %p\n", ptr);
}
void pointer_function3(int *ptr)
{
    printf("ptr = %p\n", ptr);
}

// array functions

void array_function(int arr[])
{
    printf("arr = %p\n", arr);
}
void array_function2(int arr[static 1])
{
    printf("arr = %p\n", arr);
}
void array_function3(int *arr)
{
    printf("arr = %p\n", arr);
}

// structure functions

void structure_function(point_t point)
{
    printf("point.x = %d\n", point.x);
    printf("point.y = %d\n", point.y);
}
void structure_function2(point_t *point)
{
    printf("point->x = %d\n", point->x);
    printf("point->y = %d\n", point->y);
}
void structure_function3(point_t point)
{
    printf("point.x = %d\n", point.x);
    printf("point.y = %d\n", point.y);
}

// union functions

void union_function(point_t point)
{
    printf("point.x = %d\n", point.x);
    printf("point.y = %d\n", point.y);
}

// bit field functions

void bit_field_function(bit_field_t bit_field)
{
    printf("bit_field.x = %d\n", bit_field.x);
    printf("bit_field.y = %d\n", bit_field.y);
    printf("bit_field.z = %d\n", bit_field.z);
}

// bit field functions

void bit_field_function2(bit_field_t bit_field)
{
    printf("bit_field.x = %d\n", bit_field.x);
    printf("bit_field.y = %d\n", bit_field.y);
    printf("bit_field.z = %d\n", bit_field.z);
}

// bit manipulation functions

void bit_manipulation_function(uint8_t data)
{
    printf("data = %d\n", data);
    printf("bit 0 = %d\n", (data >> 0) & 0x01);
    printf("bit 1 = %d\n", (data >> 1) & 0x01);
    printf("bit 2 = %d\n", (data >> 2) & 0x01);
    printf("bit 3 = %d\n", (data >> 3) & 0x01);
    printf("bit 4 = %d\n", (data >> 4) & 0x01);
    printf("bit 5 = %d\n", (data >> 5) & 0x01);
    printf("bit 6 = %d\n", (data >> 6) & 0x01);
    printf("bit 7 = %d\n", (data >> 7) & 0x01);
}

int main(int argc, char **argv)
{
    // array
    int arr[5] = {0, 1, 2, 3, 4};
    print_array(arr, 5);
    print_array2(arr, 5);
    print_array3(arr, 5);

    // state
    state_function(OFF);
    state_function(ON);
    state_function(IDLE);
    state_function(SLEEP);

    // pointer
    int x = 0;
    int *ptr = &x;
    pointer_function(ptr);
    pointer_function2(ptr);
    pointer_function3(ptr);

    // array
    array_function(arr);
    array_function2(arr);
    array_function3(arr);

    // structure
    point_t point = {0, 1};
    structure_function(point);
    structure_function2(&point);
    structure_function3(point);

    // union
    union_function(point);

    // bit field
    bit_field_t bit_field = {0};
    bit_field.x = 1;
    bit_field.y = 1;
    bit_field.z = 1;
    bit_field_function(bit_field);
    bit_field_function2(bit_field);

    // bit manipulation
    bit_manipulation_function(0x55);

    return 0;
}