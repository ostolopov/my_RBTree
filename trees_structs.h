#ifndef TREES_STRUCTS_H
#define TREES_STRUCTS_H

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <functional>

enum Color {RED, BLACK};

struct RBTree {
    int data;
    int key;
    Color color;
    RBTree *left;
    RBTree *right;
    RBTree *parent;
};

RBTree *create_tree ();
void print_inorder (RBTree* root);
void print_preorder (RBTree* root);
void print_postorder (RBTree* root);
void print_BFS (RBTree* root);
RBTree* tree_minimum (RBTree* node);
void left_rotate (RBTree*& root, RBTree* x);
void right_rotate (RBTree*& root, RBTree* y);
void insert_fixup (RBTree*& root, RBTree* z);
void insert_node (RBTree*& root, int data, int key);
void replace (RBTree*& root, RBTree* u, RBTree* v);
void delete_fixup (RBTree*& root, RBTree* x);
void delete_node (RBTree*& root, int key);
void delete_tree (RBTree*& root);
void print_tree (RBTree* root);
#endif
