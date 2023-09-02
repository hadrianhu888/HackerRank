/**
 * @file sorting.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdalign.h>

void simple_sort(int *arr, size_t len);
void bubble_sort(int *arr, size_t len);
void insertion_sort(int *arr, size_t len);
void selection_sort(int *arr, size_t len);
void merge_sort(int *arr, size_t len);
void quick_sort(int *arr, size_t len);
int main(int argc, char **argv);

void simple_sort(int *arr, size_t len)
{
    int i, j, temp;
    for (i = 0; i < len; i++)
    {
        for (j = i + 1; j < len; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void bubble_sort(int *arr, size_t len)
{
    int i, j, temp;
    bool swapped = false;
    for (i = 0; i < len; i++)
    {
        swapped = false;
        for (j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swapped = true;
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}

void insertion_sort(int *arr, size_t len)
{
    int i, j, temp;
    for (i = 1; i < len; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void selection_sort(int *arr, size_t len)
{
    int i, j, temp, min;
    for (i = 0; i < len - 1; i++)
    {
        min = i;
        for (j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void merge_sort(int *arr, size_t len)
{
    if (len < 2)
    {
        return;
    }
    int mid = len / 2;
    int left[mid];
    int right[len - mid];
    int i, j, k;
    for (i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }
    for (i = mid; i < len; i++)
    {
        right[i - mid] = arr[i];
    }
    merge_sort(left, mid);
    merge_sort(right, len - mid);
    i = 0;
    j = 0;
    k = 0;
    while (i < mid && j < len - mid)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = right[j];
            j++;
            k++;
        }
    }
    while (i < mid)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < len - mid)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void quick_sort(int *arr, size_t len)
{
    if (len < 2)
    {
        return;
    }
    int pivot = arr[len - 1];
    int i, j, temp;
    i = -1;
    for (j = 0; j < len - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[len - 1];
    arr[len - 1] = temp;
    quick_sort(arr, i + 1);
    quick_sort(arr + i + 2, len - i - 2);
}

int main(int argc, char **argv)
{
    int arr[] = {5, 4, 3, 2, 1};
    size_t len = sizeof(arr) / sizeof(arr[0]);
    simple_sort(arr, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bubble_sort(arr, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    insertion_sort(arr, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    selection_sort(arr, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    merge_sort(arr, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    quick_sort(arr, len);
    printf("\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}