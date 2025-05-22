#include "trees_structs.h"

// 1. создание дерева
template <> RBTree *create_tree <RBTree> () {
    return new RBTree{0, 0 , NOT,nullptr, nullptr};
}
template <> RBTreeH *create_tree <RBTreeH> () {
    return new RBTreeH{0, 0 , NOT, nullptr, nullptr};
}
template <> BinTree *create_tree <BinTree> () {
    return new BinTree{0, 0,nullptr, nullptr};
}
template <> BinTreeH *create_tree <BinTreeH> () {
    return new BinTreeH{0, 0,nullptr, nullptr};
}
template <> BalTree *create_tree <BalTree> () {
    return new BalTree{0, 0 , NOT, nullptr, nullptr};
}
template <> BalTreeH *create_tree <BalTreeH> () {
    return new BalTreeH{0, 0 , NOT, nullptr, nullptr};
}

// 2. preorder postorder inorder BFS
//post
template <> void print_postorder <RBTree> (RBTree *root) {

}

template <> void print_postorder <RBTreeH> (RBTreeH *root);
template <> void print_postorder <BinTree> (BinTree *root);
template <> void print_postorder <BinTreeH> (BinTreeH *root);
template <> void print_postorder <BalTree> (BalTree *root);
template <> void print_postorder <BalTreeH> (BalTreeH *root);

//pre
template <> void print_preorder <RBTree> (RBTree *root);
template <> void print_preorder <RBTreeH> (RBTreeH *root);
template <> void print_preorder <BinTree> (BinTree *root);
template <> void print_preorder <BinTreeH> (BinTreeH *root);
template <> void print_preorder <BalTree> (BalTree *root);
template <> void print_preorder <BalTreeH> (BalTreeH *root);

//in
template <> void print_inorder <RBTree> (RBTree *root);
template <> void print_inorder <RBTreeH> (RBTreeH *root);
template <> void print_inorder <BinTree> (BinTree *root);
template <> void print_inorder <BinTreeH> (BinTreeH *root);
template <> void print_inorder <BalTree> (BalTree *root);
template <> void print_inorder <BalTreeH> (BalTreeH *root);

//BFS
template <> void print_BFS <RBTree> (RBTree *root);
template <> void print_BFS <RBTreeH> (RBTreeH *root);
template <> void print_BFS <BinTree> (BinTree *root);
template <> void print_BFS <BinTreeH> (BinTreeH *root);
template <> void print_BFS <BalTree> (BalTree *root);
template <> void print_BFS <BalTreeH> (BalTreeH *root);

// 3. вставка элемента в дерево
template <typename T>
void insert_node (T **root);

template <> void insert_node <RBTree> (RBTree **root);
template <> void insert_node <RBTreeH> (RBTreeH **root);
template <> void insert_node <BinTree> (BinTree **root);
template <> void insert_node <BinTreeH> (BinTreeH **root);
template <> void insert_node <BalTree> (BalTree **root);
template <> void insert_node <BalTreeH> (BalTreeH **root);

// 4. удаление элемента из дерева
template <typename T>
void delete_node (T **root);

template <> void delete_node <RBTree> (RBTree **root);
template <> void delete_node <RBTreeH> (RBTreeH **root);
template <> void delete_node <BinTree> (BinTree **root);
template <> void delete_node <BinTreeH> (BinTreeH **root);
template <> void delete_node <BalTree> (BalTree **root);
template <> void delete_node <BalTreeH> (BalTreeH **root);

// 5. удаление дерева
template <typename T>
void delete_tree (T **root);

template <> void delete_tree <RBTree> (RBTree **root);
template <> void delete_tree <RBTreeH> (RBTreeH **root);
template <> void delete_tree <BinTree> (BinTree **root);
template <> void delete_tree <BinTreeH> (BinTreeH **root);
template <> void delete_tree <BalTree> (BalTree **root);
template <> void delete_tree <BalTreeH> (BalTreeH **root);

// 6. вывод дерева на экран
template <typename T>
void print_tree (T *root);

template <> void print_tree <RBTree> (RBTree *root);
template <> void print_tree <RBTreeH> (RBTreeH *root);
template <> void print_tree <BinTree> (BinTree *root);
template <> void print_tree <BinTreeH> (BinTreeH *root);
template <> void print_tree <BalTree> (BalTree *root);
template <> void print_tree <BalTreeH> (BalTreeH *root);
