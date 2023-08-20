/**
 * @file string_digit_frequency.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>lw4n88j12n1

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    for(int i = 0; i < 10; i++) {
        int count = 0;
        for(int j = 0; j < strlen(s); j++) {
            if(*(s + j) == i + '0') {
                count++;
            }
        }
        printf("%d ", count);
    }   
    return 0;
}
