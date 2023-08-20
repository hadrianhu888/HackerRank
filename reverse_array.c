/**
 * @file reverse_array.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }

    /* Write the logic to reverse the array. */
    for(i = 0; i < num / 2; i++) {
        int temp = *(arr + i);
        *(arr + i) = *(arr + num - i - 1);
        *(arr + num - i - 1) = temp;
    }

    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}

