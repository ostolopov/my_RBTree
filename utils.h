#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <climits>

#include "trees_structs.h"
#include "ind_funcs.h"

int get_int(int &number, int min, int max);

RBTree* generate_random_tree(int number);

std::string color_to_string(Color color);
void visualize_tree(RBTree* root);

#endif
