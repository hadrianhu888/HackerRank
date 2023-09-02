/**
 * @file neural_net.c
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

node_t *insert_node(node_t *root, int data)
{
    if (root == NULL)
    {
        return create_node(data);
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

void print_node(node_t *root)
{
    if (root == NULL)
        return;
    print_node(root->left);
    printf("%d ", root->data);
    print_node(root->right);
}

void test_neural_net(void)
{
    node_t *neuron = NULL;
    node_t *layer = NULL;
    node_t *network = NULL;
    node_t *input = NULL;
    node_t *output = NULL;
    node_t *weight = NULL;
    node_t *bias = NULL;
    node_t *activation = NULL;
    node_t *loss = NULL;
    node_t *optimizer = NULL;

    for (int i = 1; i <= 10; ++i)
    {
        neuron = insert_node(neuron, i);
        layer = insert_node(layer, i);
        network = insert_node(network, i);
        input = insert_node(input, i);
        output = insert_node(output, i);
        weight = insert_node(weight, i);
        bias = insert_node(bias, i);
        activation = insert_node(activation, i);
        loss = insert_node(loss, i);
        optimizer = insert_node(optimizer, i);
    }

    printf("Neurons: ");
    print_node(neuron);
    printf("\n");

    printf("Layers: ");
    print_node(layer);
    printf("\n");

    printf("Networks: ");
    print_node(network);
    printf("\n");

    printf("Inputs: ");
    print_node(input);
    printf("\n");

    printf("Outputs: ");
    print_node(output);
    printf("\n");
}

int main(int argc, char **argv)
{
    test_neural_net();
    return 0;
}
