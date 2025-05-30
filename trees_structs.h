#ifndef TREES_STRUCTS_H
#define TREES_STRUCTS_H

#include <iostream>
#include <queue>

enum Color {RED, BLACK};

struct RBTree {
    int data;
    int key;
    Color color;
    RBTree *left;
    RBTree *right;
};


RBTree *create_tree  ();
void print_postorder  (RBTree *root);
void print_preorder (RBTree *root);
void print_inorder  (RBTree *root);
void print_BFS (RBTree *root);
void insert_node (RBTree **root, int data, int key);
RBTree *delete_node (RBTree *root,int data);
void delete_tree (RBTree **root);
void print_tree (RBTree *root);


#endif
