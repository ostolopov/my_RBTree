#include "utils.h"

int get_int(int *number, int min, int max) {
    while (true) {
        if (!(std::cin >> *number)) {
            if (std::cin.eof()) {
                std::cout << "\nProgram terminated.\n";
                return 0;
            }
            std::cout << "Invalid number. Please try again!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (*number < min || *number > max) {
            std::cout << "The number is out of the allowed range. Please try again!\n";
            continue;
        }
        break;
    }
    return 1;
}

template <typename T>
void universal_case() {
    int case_number;
    T* root = nullptr;

    std::cout << "(1) Создание пустого дерева.\n"
                 "(2) Обход дерева post pre in BFS\n"
                 "(3) Включение элемента в дерево\n"
                 "(4) Удаление элемента из дерева\n"
                 "(5) Удаление всего дерева\n"
                 "(6) Вывод дерева на экран\n";
    while (get_int(&case_number, 0 ,11) != 0 && case_number != 0) {
        switch (case_number) {
            case 1:

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
    //тут жопу подтереть чтобы не текло
}

template void universal_case <RBTree> ();
template void universal_case <RBTreeH> ();
template void universal_case <BinTree> ();
template void universal_case <BinTreeH> ();
template void universal_case <BalTree> ();
template void universal_case <BalTreeH> ();
