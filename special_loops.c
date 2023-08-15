/**
 * @file special_loops.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief For each integer x in the interval [a,b] (given as input) :

If x < 9, then print the English representation of it in lowercase. That is "one" for 1, "two" for 2, and so on.
Else if x>9 and it is an even number, then print "even".
Else if x>9 and it is an odd number, then print "odd".
 * 
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void printArray(int a, int b);
void swap(int *a, int *b);
void print_even_odd(int a);
void print_number_letters(int a);

int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
    int x; 
    if (b > a)
    {
        printf("b is greater than a\n");
    }
    else if (a > b)
    {
        printf("a is greater than b\n");
        swap(&a, &b);
    }
    for (int x = a; x <= b; x++)
    {
        switch(x)
        {
            case 1:
                printf("one\n");
                print_even_odd(x);
                break;
            case 2:
                printf("two\n");
                print_even_odd(x);
                break;
            case 3:
                printf("three\n");
                print_even_odd(x);
                break;
            case 4:
                printf("four\n");
                print_even_odd(x);
                break;
            case 5:
                printf("five\n");
                print_even_odd(x);
                break;
            case 6:
                printf("six\n");
                print_even_odd(x);
                break;
            case 7:
                printf("seven\n");
                print_even_odd(x);
                break;
            case 8:
                printf("eight\n");
                print_even_odd(x);
                break;
            case 9:
                printf("nine\n");
                print_even_odd(x);
                break;
            default: 
                print_even_odd(x);
                break;
        }
    }
    x = a;
    while(x <= 0)
    {
        printf("%d\n", x);
        x++;
    }
    while (x >= 9 && x <= b)
    {
        printf("%d\n", x);
        x++; 
    }
    printf("\n");
    //print the array results here
    printArray(a, b);
    return 0;
}

void printArray(int a, int b)
{
    for (int i = a; i <= b; i++)
    {
        printf("%d\n", i);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_even_odd(int a)
{
    if (a % 2 == 0)
    {
        printf("even\n");
    }
    else if (a % 2 != 0)
    {
        printf("odd\n");
    }
}

void print_number_letters(int a)
{
    switch(a)
    {
        case 1:
            printf("one\n");
            break;
        case 2:
            printf("two\n");
            break;
        case 3:
            printf("three\n");
            break;
        case 4:
            printf("four\n");
            break;
        case 5:
            printf("five\n");
            break;
        case 6:
            printf("six\n");
            break;
        case 7:
            printf("seven\n");
            break;
        case 8:
            printf("eight\n");
            break;
        case 9:
            printf("nine\n");
            break;
        default: 
            break;
    }
    if(a > 9)
    {
        printf("Greater than 9\n");
    }
    else if (a < 1)
    {
        printf("Less than 1\n");
    }
}