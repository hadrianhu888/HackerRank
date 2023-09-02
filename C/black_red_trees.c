/**
 * @file black_red_trees.c
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

void red_black_tree(void);
void red_black_tree_test(void);

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
    bool is_red;
} node_t;

node_t *create_node(int data)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->is_red = true;
    return node;
}

node_t *delete_node(node_t *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = delete_node(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete_node(root->right, data);
    }
    else
    {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        // Case 2: One child
        else if (root->left == NULL)
        {
            node_t *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            node_t *temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3: 2 children
        else
        {
            int min = find_min(root->right);
            root->data = min;
            root->right = delete_node(root->right, min);
        }
    }
    return root;
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
        root->left->parent = root;
    }
    else
    {
        root->right = insert_node(root->right, data);
        root->right->parent = root;
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

void print_tree(node_t *root)
{
    if (root == NULL)
    {
        return;
    }
    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
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

void rotate_left(node_t **root, node_t *x) {
    node_t *y = x->right;
    x->right = y->left;

    if (y->left != NULL) {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == NULL) {
        *root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

void rotate_right(node_t **root, node_t *y) {
    node_t *x = y->left;
    y->left = x->right;

    if (x->right != NULL) {
        x->right->parent = y;
    }

    x->parent = y->parent;

    if (y->parent == NULL) {
        *root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }

    x->right = y;
    y->parent = x;
}

void fix_violations(node_t **root, node_t *z) {
    while (z->parent != NULL && z->parent->is_red) {
        if (z->parent == z->parent->parent->left) {
            node_t *y = z->parent->parent->right;

            if (y != NULL && y->is_red) {
                z->parent->is_red = false;
                y->is_red = false;
                z->parent->parent->is_red = true;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    rotate_left(root, z);
                }

                z->parent->is_red = false;
                z->parent->parent->is_red = true;
                rotate_right(root, z->parent->parent);
            }
        } else {
            node_t *y = z->parent->parent->left;

            if (y != NULL && y->is_red) {
                z->parent->is_red = false;
                y->is_red = false;
                z->parent->parent->is_red = true;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rotate_right(root, z);
                }

                z->parent->is_red = false;
                z->parent->parent->is_red = true;
                rotate_left(root, z->parent->parent);
            }
        }
    }

    (*root)->is_red = false;
}

node_t *insert_node_and_fix(node_t **root, node_t *parent, int data) {
    node_t *new_node = create_node(data);
    if (*root == NULL) {
        *root = new_node;
        (*root)->is_red = false;
        (*root)->parent = NULL;
    } else {
        new_node->parent = parent;
        if (data <= parent->data) {
            parent->left = new_node;
        } else {
            parent->right = new_node;
        }
        fix_violations(root, new_node);
    }

    return new_node;
}

void red_black_tree(void) {
    node_t *root = NULL;

    // Insert nodes
    insert_node_and_fix(&root, root, 50);
    insert_node_and_fix(&root, root, 30);
    insert_node_and_fix(&root, root, 20);
    // You can continue with more insertions

    // Perform other operations like search, find_min, etc.
    // test search, find
    assert(search(root, 50) == true);
    assert(search(root, 30) == true);
    assert(search(root, 20) == true);
    assert(search(root, 10) == false);
    assert(search(root, 40) == false);
    assert(search(root, 60) == false);

    // test find_min, find_max
    assert(find_min(root) == 20);
    assert(find_max(root) == 50);

    // test find_height
    assert(find_height(root) == 1);

    // test print_tree
    print_tree(root);
    assert(strcmp("203050", "203050") == 0);

    // test level_order_traversal
    level_order_traversal(root);

    // test is_binary_search_tree

    // test delete_node
    assert(delete_node(root, 20) == true);
}

void red_black_tree_test(void) {
    red_black_tree();
}

int main(void)
{
    red_black_tree_test();
    return 0;
}