/**
 * @file binary_search_tree.c
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
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <time.h>

void binary_search_tree(void);
void binary_search_tree_test(void);

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node_t;

node_t *create_node(int data)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

node_t *insert_node(node_t *root, int data)
{
    if (root == NULL)
    {
        root = create_node(data);
    }
    else if (data <= root->data)
    {
        root->left = insert_node(root->left, data);
    }
    else
    {
        root->right = insert_node(root->right, data);
    }
    return root;
}

bool search(node_t *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (data <= root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

int find_min(node_t *root)
{
    if (root == NULL)
    {
        printf("Error: Tree is empty\n");
        return -1;
    }
    else if (root->left == NULL)
    {
        return root->data;
    }
    else
    {
        return find_min(root->left);
    }
}

int find_max(node_t *root)
{
    if (root == NULL)
    {
        printf("Error: Tree is empty\n");
        return -1;
    }
    else if (root->right == NULL)
    {
        return root->data;
    }
    else
    {
        return find_max(root->right);
    }
}

int find_height(node_t *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        int left_height = find_height(root->left);
        int right_height = find_height(root->right);
        return (left_height > right_height) ? (left_height + 1) : (right_height + 1);
    }
}

void level_order_traversal(node_t *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%d ", root->data);
        level_order_traversal(root->left);
        level_order_traversal(root->right);
    }
}

void pre_order_traversal(node_t *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%d ", root->data);
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
}

void in_order_traversal(node_t *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        in_order_traversal(root->left);
        printf("%d ", root->data);
        in_order_traversal(root->right);
    }
}

void post_order_traversal(node_t *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        post_order_traversal(root->left);
        post_order_traversal(root->right);
        printf("%d ", root->data);
    }
}

bool is_binary_search_tree(node_t *root, int min_value, int max_value)
{
    if (root == NULL)
    {
        return true;
    }
    else if (root->data > min_value && root->data < max_value && is_binary_search_tree(root->left, min_value, root->data) && is_binary_search_tree(root->right, root->data, max_value))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void binary_search_tree(void)
{
    node_t *root = NULL;
    root = insert_node(root, 15);
    root = insert_node(root, 10);
    root = insert_node(root, 20);
    root = insert_node(root, 25);
    root = insert_node(root, 8);
    root = insert_node(root, 12);

    int number;
    printf("Enter number to be searched: ");
    scanf("%d", &number);
    if (search(root, number) == true)
    {
        printf("Found\n");
    }
    else
    {
        printf("Not found\n");
    }

    printf("Minimum value: %d\n", find_min(root));
    printf("Maximum value: %d\n", find_max(root));
    printf("Height of tree: %d\n", find_height(root));

    printf("Level order traversal: ");
    level_order_traversal(root);
    printf("\n");

    printf("Pre order traversal: ");
    pre_order_traversal(root);
    printf("\n");

    printf("In order traversal: ");
    in_order_traversal(root);
    printf("\n");

    printf("Post order traversal: ");
    post_order_traversal(root);
    printf("\n");

    if (is_binary_search_tree(root, -INFINITY, INFINITY) == true)
    {
        printf("Is binary search tree\n");
    }
    else
    {
        printf("Not a binary search tree\n");
    }
}

void binary_search_tree_test(void)
{
    binary_search_tree();
}

int main(int argc, char *argv[])
{
    binary_search_tree_test();
    return 0;
}