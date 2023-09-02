/**
 * @file sum_of_five_digits.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
    //Enter five digit number
    printf("Enter five digit number: ");
    scanf("%d", &n);
    int sum1 = 0; 
    while(n>0){
        sum1 = sum1 + n%10;
        n = n/10;
    }
    printf("%d", sum1);

/*     if(n < 10000 || n > 99999)
    {
        printf("Invalid Input");
        exit(0);
    } 
    else {
        printf("Valid Input");
        //Complete the code to calculate the sum of the five digits on n.
        int sum = 0;
        while(n>0)
        {
            sum = sum + n%10;
            n = n/10;
        }
        printf("\n");
        printf("%d", sum);
    } */
    return 0;
}