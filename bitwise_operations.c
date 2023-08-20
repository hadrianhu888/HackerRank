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

int max_OR = 0;
int max_AND = 0;
int max_XOR = 0;

/**
 * @brief n this challenge, you will use logical bitwise operators. All data is stored in its binary representation. The logical operators, and C language, use  to represent true and  to represent false. The logical operators compare bits in two numbers and return true or false,  or , for each bit compared.

Bitwise AND operator & The output of bitwise AND is 1 if the corresponding bits of two operands is 1. If either bit of an operand is 0, the result of corresponding bit is evaluated to 0. It is denoted by &.

Bitwise OR operator | The output of bitwise OR is 1 if at least one corresponding bit of two operands is 1. It is denoted by |.

Bitwise XOR (exclusive OR) operator ^ The result of bitwise XOR operator is 1 if the corresponding bits of two operands are opposite. It is denoted by .

For example, for integers 3 and 5,

3 = 00000011 (In Binary)
5 = 00000101 (In Binary)

AND operation        OR operation        XOR operation
  00000011             00000011            00000011
& 00000101           | 00000101          ^ 00000101
  ________             ________            ________
  00000001  = 1        00000111  = 7       00000110  = 6
You will be given an integer , and a threshold, i1nnik$. Print the results of the and, or and exclusive or comparisons on separate lines, in that order.

Example


The results of the comparisons are below:

a b   and or xor
1 2   0   3  3
1 3   1   3  2
2 3   2   3  1
For the and comparison, the maximum is . For the or comparison, none of the values is less than , so the maximum is . For the xor comparison, the maximum value less than  is . The function should print:

2
0
2
Function Description

Complete the calculate_the_maximum function in the editor below.

calculate_the_maximum has the following parameters:

int n: the highest number to consider
int k: the result of a comparison must be lower than this number to be considered
Prints

Print the maximum values for the and, or and xor comparisons, each on a separate line.

Input Format

The only line contains  space-separated integers,  and .

Constraints

Sample Input 0

5 4
Sample Output 0

2
3
3
Explanation 0
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */

int main(int argc, char **argv)
{
    int n, k;
    scanf("%d %d", &n, &k);
    int max_and = 0;
    int max_or = 0;
    int max_xor = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            int and = i & j;
            int or = i | j;
            int xor = i ^ j;
            if(and > max_and && and < k){
                max_and = and;
            }
            if(or > max_or && or < k){
                max_or = or;
            }
            if(xor > max_xor && xor < k){
                max_xor = xor;
            }
        }
    }
    printf("%d\n%d\n%d\n", max_and, max_or, max_xor);
    return 0;
}
