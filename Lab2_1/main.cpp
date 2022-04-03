// Variant 2.

#include <iostream>
#include <string>
#include "my_functions.h"

int main() {
	const std::string kSourceFileName = "source_text.txt", kNewFileName = "new_text.txt";
	SourceFileProcessing(kSourceFileName);
	NewFileForming(kSourceFileName, kNewFileName);
	PrintFileContent(kSourceFileName, "Source file:");
	PrintFileContent(kNewFileName, "New file:");
	return 0;
}