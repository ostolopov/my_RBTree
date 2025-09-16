#include "utils.h"

int get_int(int &number, int min, int max) {
    while (true) {
        if (!(std::cin >> number)) {
            if (std::cin.eof()) {
                std::cout << "\nProgram terminated.\n";
                return 0;
            }
            std::cout << "Invalid number. Please try again!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (number < min || number > max) {
            std::cout << "The number is out of the allowed range. Please try again!\n";
            continue;
        }
        break;
    }
    return 1;
}


RBTree* generate_random_tree(int number) {
    RBTree* root = nullptr;
    srand(time(0));
    std::cout << "Вставляем узлы.\n";
    for (int i = 0; i < number; ++i) {
        int key = rand() % 10000 + 1;
        int data = rand() % 10000 + 1;
        insert_node(root, data, key);
    }
    return root;
}


std::string color_to_string(Color c) {
    return (c == RED) ? "red" : "black";
}

void visualize_tree(RBTree* root) {
    std::ofstream dot_file("tree.dot");
    if (!dot_file.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл tree.dot\n";
        return;
    }
    dot_file << "digraph RBTree {\n";
    dot_file << "  graph [ordering=\"out\"];\n";
    dot_file << "  node [shape = circle, fontname = \"Arial\", fontcolor=white, style=filled];\n";
    if (!root) {
        dot_file << "  null [label=\"empty\", shape=circle, color=lightgray];\n";
        dot_file << "}\n";
        dot_file.close();
        std::cout << "Дерево пустое. Граф сохранён как tree.dot\n";
        return;
    }
    std::queue<RBTree*> q;
    q.push(root);
    while (!q.empty()) {
        RBTree* node = q.front(); q.pop();
        std::string label = "k: " + std::to_string(node->key) + "\\nd: " + std::to_string(node->data);
        dot_file << "  \"" << node << "\" [label=\"" << label << "\", color=" << color_to_string(node->color) << ", fillcolor=" << color_to_string(node->color) << "];\n";
        if (node->left) {
            dot_file << "  \"" << node << "\" -> \"" << node->left << "\";\n";
            q.push(node->left);
        }
        // else {
        //     dot_file << "  \"nilL" << node << "\" [label=\"NULL\", shape=circle, width=0.4, height=0.4, color=white, fillcolor=black, fontcolor=white];\n";
        //     dot_file << "  \"" << node << "\" -> \"nilL" << node << "\";\n";
        // }
        if (node->right) {
            dot_file << "  \"" << node << "\" -> \"" << node->right << "\";\n";
            q.push(node->right);
        }
        // else {
        //     dot_file << "  \"nilR" << node << "\" [label=\"NULL\", shape=circle, width=0.4, height=0.4, color=white, fillcolor=black, fontcolor=white];\n";
        //     dot_file << "  \"" << node << "\" -> \"nilR" << node << "\";\n";
        // }
    }
    dot_file << "}\n";
    dot_file.close();
    int result = system("dot -Tpng tree.dot -o tree.png && open tree.png");
    if (result != 0)
        std::cerr << "Ошибка при выполнении команды: dot -Tpng tree.dot -o tree.png\n";
    else
        std::cout << "Граф дерева сохранён как tree.png\n";
}