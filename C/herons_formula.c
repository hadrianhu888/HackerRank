/**
 * @file herons_formula.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    float p, area[n], temp;
    int i, j, k;
    for(i=0; i<n; i++)
    {
        p = (tr[i].a + tr[i].b + tr[i].c)/2.0;
        area[i] = sqrt(p*(p-tr[i].a)*(p-tr[i].b)*(p-tr[i].c));
    }
    for(j=0; j<n; j++)
    {
        for(k=j+1; k<n; k++)
        {
            if(area[j] > area[k])
            {
                temp = area[j];
                area[j] = area[k];
                area[k] = temp;
                temp = tr[j].a;
                tr[j].a = tr[k].a;
                tr[k].a = temp;
                temp = tr[j].b;
                tr[j].b = tr[k].b;
                tr[k].b = temp;
                temp = tr[j].c;
                tr[j].c = tr[k].c;
                tr[k].c = temp;
            }
        }
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}