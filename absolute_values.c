/**
 * @file absolute_values.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
/**
 * @brief 
 * 
 * @param a 
 * @param b 
 */

/**
 * @brief Complete the function void update(int *a,int *b). It receives two integer pointers, int* a and int* b. Set the value of  to their sum, and  to their absolute difference. There is no return value, and no return statement is needed.


 * 
 * @param a 
 * @param b 
 */
void update(int *a,int *b) {
    // Complete this function    
    int sum = *a + *b;
    int diff = abs(*a - *b);
    *a = sum;
    *b = diff;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}