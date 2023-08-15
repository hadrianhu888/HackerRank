/**
 * @file max_four.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include <complex.h> 
#include <stdbool.h>

/**
 * @brief Task

Write a function int max_of_four(int a, int b, int c, int d) which reads four arguments and returns the greatest of them.
 * 
 */

int main(int argc, char **argv); 

int max_of_four(int a, int b, int c, int d);

int main(int argc, char **argv){
    int a, b, c, d;
    printf("Enter your four numbers:\n");
    scanf("%d %d %d %d", &a, &b, &c, &d); 
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    return 0;
}

int max_of_four(int a, int b, int c, int d)
{
    int max = a;
    if(b > max)
    {
        max = b;
    }
    if(c > max)
    {
        max = c;
    }
    if(d > max)
    {
        max = d;
    }
    return max;
}

