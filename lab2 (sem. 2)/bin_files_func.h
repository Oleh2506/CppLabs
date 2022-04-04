#pragma once

#include <vector>
#include <string>
#include "struct_func.h"

const std::string INITIAL_LIST_NAME{ "initial_list.txt" }, SHORT_TERM_PRODUCTS_LIST_NAME{ "short_term_products_list.txt" },
LONG_TERM_PRODUCTS_LIST_NAME{ "long_term_products_list.txt" };

void WriteToBinFile(std::string file_name, std::vector <Product> products_list);

std::vector <Product> ReadFromBinFile(std::string file_name);
