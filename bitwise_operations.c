/**
 * @file bitwise_operations.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

int main(int argc, char **argv)
{
    int x;
    int y;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Enter the value of y: ");
    scanf("%d", &y);
    printf("The value of x is: %d\n", x);
    printf("The value of y is: %d\n", y);

    int max_OR = 0;
    int max_AND = 0;
    int max_XOR = 0;

    int min_OR = 0;
    int min_AND = 0;
    int min_XOR = 0;

    for (int i = 1; i <= x; i++)
    {
        for (int j = 2; j <= y; j++)
        {
            printf("The value of i is: %d\n", i);
            printf("The value of j is: %d\n", j);
            printf("The value of i AND j is: %d\n", i & j);
            printf("The value of i OR j is: %d\n", i | j);
            printf("The value of i XOR j is: %d\n", i ^ j);

            if ((i | j) > max_OR)
            {
                max_OR = i | j;
            }
            if ((i & j) > max_AND)
            {
                max_AND = i & j;
            }
            if ((i ^ j) > max_XOR)
            {
                max_XOR = i ^ j;
            }

            if ((i | j) < min_OR)
            {
                min_OR = i | j;
            }
            if ((i & j) < min_AND)
            {
                min_AND = i & j;
            }
            if ((i ^ j) < min_XOR)
            {
                min_XOR = i ^ j;
            }
        }
    }

    printf("Max OR value: %d\n", max_OR);
    printf("Max AND value: %d\n", max_AND);
    printf("Max XOR value: %d\n", max_XOR);

    printf("Min OR value: %d\n", min_OR);
    printf("Min AND value: %d\n", min_AND);
    printf("Min XOR value: %d\n", min_XOR);

    return 0;
}
