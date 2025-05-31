#include "ind_funcs.h"

// 1. Определить количество листьев на заданном уровне дерева. (андрей)
int count_leaf_nodes_at_level(RBTree* root, int lvl) {
    if (!root) return 0;
    std::queue<std::pair<RBTree*, int>> q;
    q.push({root, 0});
    int count = 0;
    while (!q.empty()) {
        auto [node, level] = q.front(); q.pop();
        if (level == lvl) {
            if (!node->left && !node->right) {
                count++;
            }
        } else if (level < lvl) {
            if (node->left) q.push({node->left, level + 1});
            if (node->right) q.push({node->right, level + 1});
        }
    }
    return count;
}

// 3. Удалить все листья на заданном уровне дерева. (соня)
void delete_leaf_nodes_at_level(RBTree*& root, int lvl) {
    if (!root) return;
    std::queue<std::pair<RBTree*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto [node, level] = q.front(); q.pop();
        if (level < lvl) {
            if (node->left) q.push({node->left, level + 1});
            if (node->right) q.push({node->right, level + 1});
        } else if (level == lvl) {
            if (!node->left && !node->right) {
                if (node->parent) {
                    if (node->parent->left == node)
                        node->parent->left = nullptr;
                    else
                        node->parent->right = nullptr;
                }
                delete node;
            }
        }
    }
}

// 5. Удалить все узлы с заданным ключом (вместе с поддеревьями, если есть). (петя)
void delete_all_nodes_with_key(RBTree*& root, int key) {
    if (!root) return;
    std::vector<RBTree*> nodes_to_delete;
    std::queue<RBTree*> q;
    q.push(root);
    while (!q.empty()) {
        RBTree* node = q.front(); q.pop();
        if (node->key == key) {
            nodes_to_delete.push_back(node);
        }
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    for (RBTree* node : nodes_to_delete) {
        if (node->parent) {
            if (node->parent->left == node)
                node->parent->left = nullptr;
            else
                node->parent->right = nullptr;
        }

        std::function<void(RBTree*)> delete_subtree = [&](RBTree* n) {
            if (!n) return;
            delete_subtree(n->left);
            delete_subtree(n->right);
            delete n;
        };

        delete_subtree(node);
    }
}

// 6. Отпечатать содержимое всех узлов, лежащих на пути между двумя узлами, заданными своими ключевыми признаками. (егор б)

RBTree* find_node(RBTree* root, int key) {
    if (!root) return nullptr;
    if (root->key == key)
        return root;
    RBTree* leftResult = find_node(root->left, key);
    if (leftResult != nullptr)
        return leftResult;
    RBTree* rightResult = find_node(root->right, key);
    return rightResult;
}

void print_all_between(RBTree* root, RBTree* node1, RBTree* node2) {

    std::function<bool(RBTree*, RBTree*, std::vector<RBTree*>&)> find_path = [&](RBTree* node, RBTree* target, std::vector<RBTree*>& path) -> bool {
            if (!node) return false;
            path.push_back(node);
            if (node == target) return true;
            if (find_path(node->left, target, path) || find_path(node->right, target, path)) {
                return true;
            }
            path.pop_back();
            return false;
    };

    std::vector<RBTree*> path1, path2;
    if (!find_path(root, node1, path1) || !find_path(root, node2, path2)) {
        std::cout << "Один из узлов не найден\n";
        return;
    }
    int i = 0;
    while (i < path1.size() && i < path2.size() && path1[i] == path2[i])
        i++;
    std::set<int> printed_keys;
    std::cout << "Узлы на пути между ключами " << node1->key << " и " << node2->key << ":\n";
    for (int j = i - 1; j < path1.size(); j++) {
        if (printed_keys.insert(path1[j]->key).second) {
            std::cout << "k: " << path1[j]->key << ", d: " << path1[j]->data << "\n";
        }
    }
    for (int j = i - 1; j < path2.size(); j++) {
        if (printed_keys.insert(path2[j]->key).second)
            std::cout << "k: " << path2[j]->key << ", d: " << path2[j]->data << "\n";
    }
}


// 10. Определить количество узлов (не листьев) бинарного дерева на определенном уровне (егор п )
int count_non_leaf_nodes_at_level(RBTree* root, int lvl) {
    if (!root) return 0;
    std::queue<std::pair<RBTree*, int>> q;
    q.push({root, 0});
    int count = 0;
    while (!q.empty()) {
        auto [node, level] = q.front(); q.pop();
        if (level == lvl) {
            if (node->left || node->right) {
                count++;
            }
        } else if (level < lvl) {
            if (node->left) q.push({node->left, level + 1});
            if (node->right) q.push({node->right, level + 1});
        }
    }
    return count;
}

//12.Определить, являются ли два поддерева, заданные своими корнями (с помощью значений ключевого признака) тождественными по структуре (заман)

// void are_tree_equal(RBTree* root, int key1, int key2) {
//     std::function<bool(RBTree*, RBTree*)> are_trees_equal = [&](RBTree* a, RBTree* b) -> bool {
//         if (!a && !b) return true;
//         if (!a || !b) return false;
//         return (a->key == b->key &&
//                 are_trees_equal(a->left, b->left) &&
//                 are_trees_equal(a->right, b->right));
//     };
//
//     RBTree* node1 = find_node(root, key1);
//     RBTree* node2 = find_node(root, key2);
//     if (!node1 || !node2) {
//         std::cout << "Один из узлов не найден.\n";
//         return;
//     }
//     if (are_trees_equal(node1, node2))
//         std::cout << "Поддеревья тождественны.\n";
//     else
//         std::cout << "Поддеревья НЕ тождественны.\n";
// }

void are_tree_equal(RBTree* root, int key1, int key2) {

    std::function<bool(RBTree*, RBTree*)> are_trees_equal = [&](RBTree* a, RBTree* b) -> bool {
        if (!a && !b) return true;
        if (!a || !b) return false;
        return are_trees_equal(a->left, b->left) && are_trees_equal(a->right, b->right);
    };

    RBTree* node1 = find_node(root, key1);
    RBTree* node2 = find_node(root, key2);
    if (!node1 || !node2) {
        std::cout << "Один из узлов не найден.\n";
        return;
    }
    if (are_trees_equal(node1, node2))
        std::cout << "Поддеревья имеют одинаковую структуру.\n";
    else
        std::cout << "Поддеревья имеют РАЗНУЮ структуру.\n";
}