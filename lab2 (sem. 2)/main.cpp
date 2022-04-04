// Variant 2.

#include <iostream>
#include "struct_func.h"
#include <vector>
#include "bin_files_func.h"

int main() {
	std::string current_date{ "12-12-2022" };

	std::vector <Product> initial_list = GetContent(current_date);
	WriteToBinFile(INITIAL_LIST_NAME, initial_list);
	initial_list.clear();

	initial_list = ReadFromBinFile(INITIAL_LIST_NAME);
	std::cout << "\nInitial list of products:\n";
	PrintProductsList(initial_list);

	std::vector <Product> short_term_products_list = GetShortTermStorageProducts(initial_list);
	WriteToBinFile(SHORT_TERM_PRODUCTS_LIST_NAME, short_term_products_list);
	short_term_products_list.clear();

	short_term_products_list = ReadFromBinFile(SHORT_TERM_PRODUCTS_LIST_NAME);
	std::cout << "\nShort term storage products list:\n";
	PrintProductsList(short_term_products_list);

	std::vector <Product> long_term_products_list = GetLongTermStorageProducts(initial_list);
	WriteToBinFile(LONG_TERM_PRODUCTS_LIST_NAME, long_term_products_list);
	long_term_products_list.clear();

	long_term_products_list = ReadFromBinFile(LONG_TERM_PRODUCTS_LIST_NAME);
	std::cout << "\nLong term storage products list:\n";
	PrintProductsList(long_term_products_list);

	DeleteExpiredProducts(short_term_products_list, StringToDate(current_date));
	std::cout << "\nShort term storage products list after deleting expired products:\n";
	PrintProductsList(short_term_products_list);

	DeleteExpiredProducts(long_term_products_list, StringToDate(current_date));
	std::cout << "\nLong term storage products list after deleting expired products:\n";
	PrintProductsList(long_term_products_list);
	return 0;
}