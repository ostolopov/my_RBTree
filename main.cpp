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
                 "(8) Сгенерировать дерево\n"
                 "(9) Количество листьев на уровне (Андрей)\n"
                 "(10) Удалить листья на уровне (Соня)\n"
                 "(11) Удалить узлы по ключу (с поддеревьями) (Петя)\n"
                 "(12) Печать узлов между двумя узлами (Егор Б.)\n"
                 "(13) Количество не-листовых узлов на уровне (Заман)\n"
                 "(14) Сравнить два поддерева по структуре (Егор П.)\n";
    while (get_int(case_number, 0 ,15) != 0 && case_number != 0) {
        switch (case_number) {
            case 1:
                root = create_tree();
                break;
            case 2:
                std::cout << "post: ";
                print_postorder(root);
                std::cout << std::endl << "pre: ";
                print_preorder(root);
                std::cout << std::endl << "in: ";
                print_inorder(root);
                std::cout << std::endl << "BFS: ";
                print_BFS(root);
                std::cout << std::endl;
                break;
            case 3:
                std::cout << "Введите data, key:\n";
                get_int(data, 0, INT_MAX);
                get_int(key, 0, INT_MAX);
                insert_node(root, data, key);
                break;
            case 4:
                std::cout << "Введите значение ключа элемента дерева для удаления:\n";
                get_int(key, 0, INT_MAX);
                delete_node(root, key);
                break;
            case 5:
                delete_tree(root);
                root = nullptr;
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
                break;

            case 9: {
                int level;
                std::cout << "Введите уровень для подсчёта листьев:\n";
                get_int(level, 0, 100);
                int count = count_leaf_nodes_at_level(root, level);
                std::cout << "Количество листьев на уровне " << level << ": " << count << "\n";
                break;
            }
            case 10: {
                int level;
                std::cout << "Введите уровень для удаления листьев:\n";
                get_int(level, 0, 100);
                delete_leaf_nodes_at_level(root, level);
                std::cout << "Листья на уровне " << level << " удалены.\n";
                break;
            }

            case 11: {
                std::cout << "Введите ключ для удаления узла (вместе с поддеревом):\n";
                get_int(key, 0, INT_MAX);
                delete_all_nodes_with_key(root, key);
                std::cout << "Все узлы с ключом " << key << " удалены.\n";
                break;
            }
            case 12: {
                int key1, key2;
                std::cout << "Введите ключ первого узла:\n";
                get_int(key1, 0, INT_MAX);
                std::cout << "Введите ключ второго узла:\n";
                get_int(key2, 0, INT_MAX);
                RBTree* node1 = find_node(root, key1);
                RBTree* node2 = find_node(root, key2);
                if (!node1 || !node2)
                    std::cout << "Один из узлов не найден.\n";
                else
                    print_all_between(root, node1, node2);
                break;
            }
            case 13: {
                int level;
                std::cout << "Введите уровень для подсчёта не-листовых узлов:\n";
                get_int(level, 0, 100);
                int count = count_non_leaf_nodes_at_level(root, level);
                std::cout << "Количество не-листовых узлов на уровне " << level << ": " << count << "\n";
                break;
            }
            case 14: {
                int key1, key2;
                std::cout << "Введите ключ корня первого поддерева:\n";
                get_int(key1, 0, INT_MAX);
                std::cout << "Введите ключ корня второго поддерева:\n";
                get_int(key2, 0, INT_MAX);
                are_tree_equal(root, key1, key2);
                break;
            }

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
                 "(8) Сгенерировать дерево\n"
                 "(9) Количество листьев на уровне (Андрей)\n"
                 "(10) Удалить листья на уровне (Соня)\n"
                 "(11) Удалить узлы по ключу (с поддеревьями) (Петя)\n"
                 "(12) Печать узлов между двумя узлами (Егор Б.)\n"
                 "(13) Количество не-листовых узлов на уровне (Егор П.)\n"
                 "(14) Сравнить два поддерева по структуре (Заман)\n";
    }
    delete_tree(root);
    return 0;
}