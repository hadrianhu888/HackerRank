/**
 * @file deques_queues.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

typedef struct node
{
    int data;
    struct node *next;
} node_t;

typedef struct
{
    node_t *head;
    node_t *tail;
    int size;
} list_t;

list_t *create_list(void)
{
    list_t *list = malloc(sizeof(list_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void destroy_list(list_t *list)
{
    node_t *current = list->head;
    while (current != NULL)
    {
        node_t *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

void print_list(list_t *list)
{
    node_t *current = list->head;
    while (current != NULL)
    {
        printf("current->data = %d\n", current->data);
        current = current->next;
    }
}

void push_front(list_t *list, int value)
{
    node_t *node = malloc(sizeof(node_t));
    node->data = value;
    node->next = list->head;
    list->head = node;
    if (list->tail == NULL)
    {
        list->tail = node;
    }
    list->size++;
}

void push_back(list_t *list, int value)
{
    node_t *node = malloc(sizeof(node_t));
    node->data = value;
    node->next = NULL;
    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

void pop_front(list_t *list)
{
    if (list->head == NULL)
    {
        return;
    }
    else if (list->head == list->tail)
    {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        node_t *next = list->head->next;
        free(list->head);
        list->head = next;
    }
    list->size--;
}

void pop_back(list_t *list)
{
    if (list->head == NULL)
    {
        return;
    }
    else if (list->head == list->tail)
    {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        node_t *current = list->head;
        while (current->next != list->tail)
        {
            current = current->next;
        }
        free(list->tail);
        list->tail = current;
        list->tail->next = NULL;
    }
    list->size--;
}

int front(list_t *list)
{
    assert(list->head != NULL);
    return list->head->data;
}

int back(list_t *list)
{
    assert(list->tail != NULL);
    return list->tail->data;
}

bool empty(list_t *list)
{
    return list->head == NULL;
}

int size(list_t *list)
{
    return list->size;
}

int main(int argc, char **argv)
{
    list_t *list = create_list();
    push_back(list, 1);
    push_back(list, 2);
    push_back(list, 3);
    push_front(list, 0);
    print_list(list);
    printf("front = %d\n", front(list));
    printf("back = %d\n", back(list));
    printf("size = %d\n", size(list));
    pop_front(list);
    pop_back(list);
    print_list(list);
    printf("front = %d\n", front(list));
    printf("back = %d\n", back(list));
    printf("size = %d\n", size(list));
    destroy_list(list);
    return 0;
}
