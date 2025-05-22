#ifndef IND_FUNCS_H
#define IND_FUNCS_H

#include <iostream>
#include "trees_structs.h"
#include "ind_funcs.h"
#include "utils.h"

// 1. Определить количество листьев на заданном уровне дерева.
template <typename T>
void count_nodes_level (T* root);

// 3. Удалить все листья на заданном уровне дерева.

template <typename T>
void delete_all_nodes_level (T** root);

// 5. Удалить все узлы с заданным ключом (вместе с поддеревьями, если есть).

template <typename T>
void delete_all_nodes_key (T** root);

// 6. Отпечатать содержимое всех узлов, лежащих на пути между двумя узлами, заданными своими ключевыми признаками.

template <typename T>
void print_all_between (T* root);

//егор заман тоже

#endif
