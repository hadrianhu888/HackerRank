/**
 * @file list.c
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

void push_front(list_t *list, int value)
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
        node->next = list->head;
        list->head = node;
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
        node_t *current = list->head;
        list->head = list->head->next;
        free(current);
    }
    list->size--;
}

void insert(list_t *list, int index, int value)
{
    if (index < 0 || index > list->size)
    {
        return;
    }
    else if (index == 0)
    {
        push_front(list, value);
    }
    else if (index == list->size)
    {
        push_back(list, value);
    }
    else
    {
        node_t *current = list->head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        node_t *node = malloc(sizeof(node_t));
        node->data = value;
        node->next = current->next;
        current->next = node;
        list->size++;
    }
}

void erase(list_t *list, int index)
{
    if (index < 0 || index >= list->size)
    {
        return;
    }
    else if (index == 0)
    {
        pop_front(list);
    }
    else if (index == list->size - 1)
    {
        pop_back(list);
    }
    else
    {
        node_t *current = list->head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        node_t *next = current->next->next;
        free(current->next);
        current->next = next;
        list->size--;
    }
}

int main(int argc, char **argv)
{
    list_t *list = create_list();
    push_back(list, 1);
    push_back(list, 2);
    push_back(list, 3);
    push_back(list, 4);
    push_back(list, 5);
    print_list(list);
    pop_back(list);
    pop_back(list);
    pop_back(list);
    print_list(list);
    push_front(list, 1);
    push_front(list, 2);
    push_front(list, 3);
    push_front(list, 4);
    push_front(list, 5);
    print_list(list);
    pop_front(list);
    pop_front(list);
    pop_front(list);
    print_list(list);
    insert(list, 0, 1);
    insert(list, 1, 2);
    insert(list, 2, 3);
    insert(list, 3, 4);
    insert(list, 4, 5);
    print_list(list);
    erase(list, 0);
    erase(list, 1);
    erase(list, 2);
    print_list(list);
    destroy_list(list);
    return 0;
}