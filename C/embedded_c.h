/**
 * @file embedded_c.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef EMBEDDED_C_H
#define EMBEDDED_C_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <float.h>
#include <limits.h>

// Function prototypes

// simply embedded programming structures and functions 

// #define DEBUG

typedef struct {
    int x;
    int y;
} point_t;

typedef struct {
    int x;
    int y;
    int z;
} point3d_t;

typedef enum state
{
    OFF,
    ON,
    IDLE,
    SLEEP
} state_t;

// union structure 
typedef union {
    uint8_t data;
    struct {
        uint8_t bit0 : 1;
        uint8_t bit1 : 1;
        uint8_t bit2 : 1;
        uint8_t bit3 : 1;
        uint8_t bit4 : 1;
        uint8_t bit5 : 1;
        uint8_t bit6 : 1;
        uint8_t bit7 : 1;
    } bits;
} data_t;

// bit field structure

typedef struct {
    uint8_t x : 1;
    uint8_t y : 1;
    uint8_t z : 1;
} bit_field_t;

// Function prototypes

void print_array(int *arr, int size);
void print_array2(int arr[], int size);
void print_array3(int arr[static 1], int size);

// state functions 

void state_function(state_t state);
state_t state_function2(state_t state);
state_t state_function3(state_t state);

// pointer functions

void pointer_function(int *ptr);
void pointer_function2(int *ptr);
void pointer_function3(int *ptr);

// array functions

void array_function(int arr[]);
void array_function2(int arr[static 1]);
void array_function3(int *arr);

// structure functions

void structure_function(point_t point);
void structure_function2(point_t *point);
void structure_function3(point_t point);

// union functions

void union_function(point_t point);

// bit field functions

void bit_field_function(bit_field_t bit_field);
void bit_field_function2(bit_field_t bit_field);

// bit manipulation functions

void bit_manipulation_function(uint8_t data);

int main(int argc, char **argv);

#endif

// Path: embedded_c.h