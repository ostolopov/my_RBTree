#include <iostream>

#include "trees_structs.h"
#include "ind_funcs.h"
#include "utils.h"

int main() {
    int data;
    int case_number;
    RBTree* root = nullptr;
    std::cout << "(1) Создание пустого дерева.\n"
                 "(2) Обход дерева post pre in BFS\n"
                 "(3) Включение элемента в дерево\n"
                 "(4) Удаление элемента из дерева\n"
                 "(5) Удаление всего дерева\n"
                 "(6) Вывод дерева на экран\n";
    while (get_int(&case_number, 0 ,11) != 0 && case_number != 0) {
        switch (case_number) {
            case 1:
                root = create_tree();
            break;
            case 2:
                print_postorder (root);
            print_preorder(root);
            print_inorder(root);
            print_BFS(root);
            break;
            case 3:
                insert_node(&root));
            break;
            case 4:
                delete_node(&root, data);
            break;
            case 5:
                delete_tree(&root);
            break;
            case 6:
                print_tree(root);
            break;
            default:
                std::cout << "Число вне диапазона\n";
            break;
        }
        std::cout << "(1) Создание пустого дерева.\n"
                 "(2) Обход дерева post pre in BFS\n"
                 "(3) Включение элемента в дерево\n"
                 "(4) Удаление элемента из дерева\n"
                 "(5) Удаление всего дерева\n"
                 "(6) Вывод дерева на экран\n";
    }
    delete_tree(&root);
    return 0;
}

