#include <iostream>

#include "trees_structs.h"
#include "ind_funcs.h"
#include "utils.h"

int main() {
    int data, key, number;
    int case_number;
    RBTree* root = nullptr;
    std::cout << "(1) Создание пустого дерева.\n"
                 "(2) Обход дерева post pre in BFS\n"
                 "(3) Включение элемента в дерево\n"
                 "(4) Удаление элемента из дерева\n"
                 "(5) Удаление всего дерева\n"
                 "(6) Вывод дерева на экран (запутался в отрисовке говно полное)\n"
                 "(7) Вывод дерева PNG\n"
                 "(8) Сгенерировать дерево\n";
    while (get_int(case_number, 0 ,11) != 0 && case_number != 0) {
        switch (case_number) {
            case 1:
                root = create_tree();
            break;
            case 2:
                print_postorder (root);
                std::cout << std::endl;
                print_preorder(root);
                std::cout << std::endl;
                print_inorder(root);
                std::cout << std::endl;
                print_BFS(root);
                std::cout << std::endl;
                break;
            case 3:
                std::cout << "Введите data ,key:\n";
                get_int(data, 0 ,INT_MAX);
                get_int(key, 0 ,INT_MAX);
                insert_node(root, data , key);
                break;
            case 4:
                std::cout << "Введите значение ключа элемента дерева для удаления:\n";
                get_int(key, 0, INT_MAX);
                delete_node(root, key);
                break;
            case 5:
                delete_tree(root);
                break;
            case 6:
                //print_tree(root);
                break;
            case 7:
                visualize_tree(root);
                break;
            case 8:
                 std::cout << "Введите количество элементов для генерации:\n";
                get_int(number, 0, 10000);
                root = generate_random_tree(number);
            default:
                std::cout << "Число вне диапазона\n";
                break;
        }
        std::cout << "(1) Создание пустого дерева.\n"
                 "(2) Обход дерева post pre in BFS\n"
                 "(3) Включение элемента в дерево\n"
                 "(4) Удаление элемента из дерева\n"
                 "(5) Удаление всего дерева\n"
                 "(6) Вывод дерева на экран (запутался в отрисовке говно полное)\n"
                 "(7) Вывод дерева PNG\n"
                 "(8) Сгенерировать дерево\n";
    }
    delete_tree(root);
    return 0;
}

