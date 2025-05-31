#ifndef IND_FUNCS_H
#define IND_FUNCS_H

#include <iostream>
#include <functional>
#include <set>
#include <queue>
#include <vector>

#include "trees_structs.h"
#include "ind_funcs.h"
#include "utils.h"

// 1. Определить количество листьев на заданном уровне дерева.
int count_leaf_nodes_at_level(RBTree* root, int lvl);
// 3. Удалить все листья на заданном уровне дерева.
void delete_leaf_nodes_at_level(RBTree*& root, int lvl);
// 5. Удалить все узлы с заданным ключом (вместе с поддеревьями, если есть).
void delete_all_nodes_with_key(RBTree*& root, int key);
// 6. Отпечатать содержимое всех узлов, лежащих на пути между двумя узлами, заданными своими ключевыми признаками.
RBTree* find_node(RBTree* root, int key);
void print_all_between(RBTree* root, RBTree* node1, RBTree* node2);
// 10. Определить количество узлов (не листьев) бинарного дерева (егор)
int count_non_leaf_nodes_at_level(RBTree* root, int lvl);
//12.Определить, являются ли два поддерева, заданные своими корнями (с помощью значений ключевого признака) тождественными по структуре (заман)
void are_tree_equal(RBTree* root, int key1, int key2);
#endif
