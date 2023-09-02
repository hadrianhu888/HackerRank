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
int main(int argc, char **argv); 

int main(int argc, char **argv)
{
    int a, b;
    //printf("Enter two numbers: \n");
    scanf("%d\n%d", &a, &b);
    printArray(a, b);
    return 0;
}

void printArray(int a, int b)
{
    int i;
    for (i = a; i <= b; i++)
    {
        if (i >= 1 && i <= 9)
        {
            print_number_letters(i);
        }
        else
        {
            print_even_odd(i);
        }
    }
}

void print_number_letters(int a)
{
    switch (a)
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
} 

void print_numbers_to_letters(int a, int b)
{
    for(int i=a; i<=b; i++)
    {
        if(i>=1 && i <=9)
        {
            print_number_letters(i);
        }
        else if (i > 9)
        {
            print_even_odd(i);
        }
    }
}

void print_even_odd(int a)
{
    if (a % 2 == 0)
    {
        printf("even\n");
    }
    else
    {
        printf("odd\n");
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b=temp;
}


