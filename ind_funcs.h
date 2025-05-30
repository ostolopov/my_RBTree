#ifndef IND_FUNCS_H
#define IND_FUNCS_H

#include <iostream>
#include "trees_structs.h"
#include "ind_funcs.h"
#include "utils.h"

// 1. Определить количество листьев на заданном уровне дерева.

void count_nodes_level (RBTree* root);

// 3. Удалить все листья на заданном уровне дерева.
void delete_all_nodes_level (RBTree** root);

// 5. Удалить все узлы с заданным ключом (вместе с поддеревьями, если есть).
void delete_all_nodes_key (RBTree** root);

// 6. Отпечатать содержимое всех узлов, лежащих на пути между двумя узлами, заданными своими ключевыми признаками.
void print_all_between (RBTree* root);

//егор заман тоже
// void
// void

#endif
