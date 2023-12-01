#include <stddef.h>
#include "bintree.h"
#include <stdlib.h>
#include<stdio.h>

// Recall node is defined in the header file
node *root = NULL;

// Insert a new node into the binary tree with node_id and data
void insert_node(int node_id, int data) {
    if(root == NULL){
        root = (node*)malloc(sizeof(node));
        root->data = data;
        root->node_id = node_id;
        root->left = NULL;
        root->right = NULL;
    }else{
        node* new_node = (node*)malloc(sizeof(node));
        new_node->data = data;
        new_node->node_id = node_id;
        new_node->left = NULL;
        new_node->right = NULL;
        node* parent = root;
    findparent:
        if(new_node->node_id < parent->node_id){
            if(parent->left != NULL){
                parent = parent->left;
                goto findparent;
            }else{
                parent->left = new_node;
                return;
            }
            }else{
                if(parent->right != NULL){
                    parent = parent->right;
                    goto findparent;
                }else{
                    parent->right = new_node;
                    return;
                }
            }
    }
}

// Find the node with node_id, and return its data
node* find_node(int node_id) {
	node* current = root;
    while(current != NULL){
        if(current->node_id == node_id){
            return current;
        }else{
            if(node_id < current->node_id){
                current = current -> left;
            }else{
                current = current -> right;
            }
        }
    }
    return NULL;
}

/*//Find and remove a node in the binary tree with node_id. 
//Children nodes are fixed appropriately.
*/
void remove_node(int node_id) {
	node* target;
    node* parent = root;
    while(1){
        if(node_id < parent->node_id){
            if(parent->left->node_id == node_id){
                target=parent->left;
                if(target->left==NULL && target->right==NULL){
                    free(target);
                    parent->left = NULL;
                    break;
                }else if(target->left->left==NULL && target->left->right==NULL
                    && target->right->left==NULL && target->right->right==NULL){
                        if(target->right != NULL){
                            target->right->left=target->left;
                            parent->left = target->right;
                            free(target);
                            break;
                        }else{
                            parent->left = target->left;
                            free(target);
                            break;
                        }
                }else{
                    node* parent_target_replace = target;
                    node* target_replace = target->right;
                    while(target_replace->left!=NULL){
                        parent_target_replace = target_replace;
                        target_replace=target_replace->left;
                    }
                    if(target_replace==target->right){
                        target_replace->left=target->left;
                    }
                    if(target_replace->right!=NULL && target_replace!=target->right){
                        parent_target_replace->left=target_replace->right;
                    }
                    parent->left=target_replace;
                    free(target);
                    break;
                }
            }else{
                parent = parent->left;
            }
        }else{
            if(parent->right->node_id == node_id){
                target=parent->right;
                if(target->left==NULL && target->right==NULL){
                    free(target);
                    parent->right = NULL;
                    break;
                }else if(target->left->left==NULL && target->left->right==NULL
                    && target->right->left==NULL && target->right->right==NULL){
                        if(target->right != NULL){
                            target->right->left=target->left;
                            parent->right = target->right;
                            free(target);
                            break;
                        }else{
                            parent->right = target->left;
                            free(target);
                            break;
                        }
                }else{
                    node* parent_target_replace = target;
                    node* target_replace = target->right;
                    while(target_replace->left!=NULL){
                        parent_target_replace = target_replace;
                        target_replace=target_replace->left;
                    }
                    if(target_replace==target->right){
                        target_replace->left=target->left;
                    }
                    if(target_replace->right!=NULL && target_replace!=target->right){
                        parent_target_replace->left=target_replace->right;
                    }
                    parent->right=target_replace;
                    free(target);
                    break;
                }
            }else{
                parent = parent->right;
            }
        }
    }
}
