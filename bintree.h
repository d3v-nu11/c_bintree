#ifndef BINTREE_H
#define BINTREE_H

// Node structure has an int node_id, an int data, and pointers to left and right child nodes
typedef struct node {
    int node_id;
    int data;
    struct node* left;
    struct node* right;
} node;

void insert_node(int node_id, int data);
node* find_node(int node_id);
void remove_node(int node_id);

#endif
