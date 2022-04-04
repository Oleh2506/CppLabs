#include "bin_files_func.h"
#include <fstream>
#include "struct_func.h"

void WriteToBinFile(std::string file_name, std::vector <Product> products_list) {
	std::ofstream out_file(file_name, std::ios::binary | std::ios::trunc);

	for (size_t i{ 0 }; i < products_list.size(); ++i) {
		out_file.write((char*)&products_list[i], sizeof(Product));
	}

	out_file.close();
}

std::vector <Product> ReadFromBinFile(std::string file_name) {
	std::ifstream in_file(file_name, std::ios::binary);
	Product curr;
	std::vector <Product> products_list;

	while (in_file.read((char*)&curr, sizeof(Product))) {
		products_list.push_back(curr);
	}

	in_file.close();
	return products_list;
}