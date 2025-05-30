#include "trees_structs.h"

RBTree *create_tree  () {
    return nullptr;
}

void print_inorder (RBTree* root) {
    if (root) {
        print_inorder(root->left);
        std::cout <<"k:" << root->key << " d:" << root->data << " c:" << root->color << " -> ";
        print_inorder(root->right);
    }
}

void print_preorder (RBTree* root) {
    if (root) {
        std::cout <<"k:" << root->key << " d:" << root->data << " c:" << root->color << " -> ";
        print_preorder(root->left);
        print_preorder(root->right);
    }
}

void print_postorder (RBTree* root) {
    if (root) {
        print_postorder(root->left);
        print_postorder(root->right);
        std::cout <<"k:" << root->key << " d:" << root->data << " c:" << root->color << " -> ";
    }
}

void print_BFS(RBTree* root) {
    if (!root) return;
    std::queue<RBTree*> q;
    q.push(root);
    while (!q.empty()) {
        RBTree* node = q.front(); q.pop();
        std::cout <<"k:" << root->key << " d:" << root->data << " c:" << root->color << " -> ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    std::cout << "\n";
}



// вставка 342стр , вроде работает я хз
RBTree* tree_minimum(RBTree* node) {
    while (node->left != nullptr)
        node = node->left;
    return node;
}

void left_rotate(RBTree*& root, RBTree* x) {
    RBTree* y = x->right;
    x->right = y->left;
    if (y->left != nullptr)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == nullptr)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void right_rotate(RBTree*& root, RBTree* y) {
    RBTree* x = y->left;
    y->left = x->right;
    if (x->right != nullptr)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == nullptr)
        root = x;
    else if (y == y->parent->right)
        y->parent->right = x;
    else
        y->parent->left = x;
    x->right = y;
    y->parent = x;
}


// Свойства красно-черных деревьев:
// 1) Каждый узел окрашен либо в красный, либо в черный цвет (в структуре данных узла появляется дополнительное поле – бит цвета).
// 2) Корень окрашен в черный цвет.
// 3) Листья(так называемые NULL-узлы) окрашены в черный цвет.
// 4) Каждый красный узел должен иметь два черных дочерних узла. Нужно отметить, что у черного узла могут быть черные дочерние узлы.
//    Красные узлы в качестве дочерних могут иметь только черные.
// 5) Пути от узла к его листьям должны содержать одинаковое количество черных узлов(это черная высота).

void insert_fixup(RBTree*& root, RBTree* z) {
    while (z != root && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            RBTree* y = z->parent->parent->right;
            if (y != nullptr && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    left_rotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                right_rotate(root, z->parent->parent);
            }
        } else {
            RBTree* y = z->parent->parent->left;
            if (y != nullptr && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    right_rotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                left_rotate(root, z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

void insert_node (RBTree*& root, int data, int key) {
    RBTree* z = new RBTree(key, data, RED);
    RBTree* y = nullptr;
    RBTree* x = root;
    while (x != nullptr) {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if (y == nullptr)
        root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
    insert_fixup(root, z);
}


//удаление 351стр   бож че не так
void replace(RBTree*& root, RBTree* u, RBTree* v) {
    if (u->parent == nullptr)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    if (v != nullptr)
        v->parent = u->parent;
}

// Свойства красно-черных деревьев:
// 1) Каждый узел окрашен либо в красный, либо в черный цвет (в структуре данных узла появляется дополнительное поле – бит цвета).
// 2) Корень окрашен в черный цвет.
// 3) Листья(так называемые NULL-узлы) окрашены в черный цвет.
// 4) Каждый красный узел должен иметь два черных дочерних узла. Нужно отметить, что у черного узла могут быть черные дочерние узлы.
//    Красные узлы в качестве дочерних могут иметь только черные.
// 5) Пути от узла к его листьям должны содержать одинаковое количество черных узлов(это черная высота).

void delete_fixup(RBTree*& root, RBTree* x) {
    while (x != root && x->color == BLACK) {
        if (x == x->parent->left) {
            RBTree* w = x->parent->right;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                left_rotate(root, x->parent);
                w = x->parent->right;
            }
            if ((w->left == nullptr || w->left->color == BLACK) &&
                (w->right == nullptr || w->right->color == BLACK)) {
                w->color = RED;
                x = x->parent;
            } else {
                if ((w->right == nullptr || w->right->color == BLACK)) {
                    if (w->left != nullptr)
                        w->left->color = BLACK;
                    w->color = RED;
                    right_rotate(root, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                if (w->right != nullptr)
                    w->right->color = BLACK;
                left_rotate(root, x->parent);
                x = root;
            }
        } else {
            RBTree* w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                right_rotate(root, x->parent);
                w = x->parent->left;
            }
            if ((w->right == nullptr || w->right->color == BLACK) &&
                (w->left == nullptr || w->left->color == BLACK)) {
                w->color = RED;
                x = x->parent;
            } else {
                if ((w->left == nullptr || w->left->color == BLACK)) {
                    if (w->right != nullptr)
                        w->right->color = BLACK;
                    w->color = RED;
                    left_rotate(root, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                if (w->left != nullptr)
                    w->left->color = BLACK;
                right_rotate(root, x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

void delete_node (RBTree*& root, int key) {
    RBTree* z = root;
    while (z != nullptr && z->key != key)
        z = (key < z->key) ? z->left : z->right;
    if (z == nullptr) return;
    Color original_color = z->color;
    RBTree* x;
    RBTree* y = z;
    if (z->left == nullptr || z->right == nullptr) {
        if (z->left == nullptr)
            x = z->right;
        else
            x = z->left;
        if (original_color == BLACK)
            delete_fixup(root, x);
        if (z->parent == nullptr)
            root = x;
        else if (z == z->parent->left)
            z->parent->left = x;
        else
            z->parent->right = x;
        if (x != nullptr)
            x->parent = z->parent;
        delete z;
    } else {
        y = tree_minimum(z->right);
        original_color = y->color;
        x = y->right;
        if (y->parent == z)
            x->parent = y;
        else {
            replace(root, y, y->right);
            y->right = z->right;
            if (y->right != nullptr)
                y->right->parent = y;
        }
        replace(root, z, y);
        y->left = z->left;
        if (y->left != nullptr)
            y->left->parent = y;
        y->color = z->color;
        if (original_color == BLACK)
            delete_fixup(root, x);
        delete z;
    }
}

void delete_tree(RBTree*& root) {
    std::function<void(RBTree*)> del = [&](RBTree* node) {
        if (!node) return;
        del(node->left);
        del(node->right);
        delete node;
    };
    del(root);
    root = nullptr;
}


