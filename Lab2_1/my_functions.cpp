#include <iostream>
#include <fstream>
#include <string>

// Prints message and content of the file 
void PrintFileContent(const std::string kFileName, const std::string kMessage) {
	std::cout << kMessage << "\n";

	std::ifstream in_file(kFileName, std::ios::in);
	if (in_file.is_open()) {
		std::string current_line{};
		while (!in_file.eof()) {
			getline(in_file, current_line);
			std::cout << current_line << "\n";
		}
	}
	else {
		std::cout << "Error: can\'t open the file!\n";
	}

	in_file.close();
}

// Returns true if file contains at least one line starting with conditional character '#' and false if not
bool IsSourceFileConditional(const std::string kFileName) {
	bool file_is_conditional{ false };
	const char kConditionalChar = '#';

	std::ifstream in_file(kFileName, std::ios::in);
	if (in_file.is_open()) {
		std::string current_line{};
		while (!in_file.eof() && !file_is_conditional) {
			getline(in_file, current_line);
			if (current_line.length() && current_line.at(0) == kConditionalChar) {
				file_is_conditional = true;
			}
		}
	}
	else {
		std::cout << "Error: can\'t open the file!\n";
	}

	in_file.close();
	return file_is_conditional;
}

// Extends initial text file with entered text
void AppendTextToFile(const std::string kFileName, const std::string kText) {
	std::ofstream app_file(kFileName, std::ios::app);
	if (app_file.is_open()) {
		app_file << kText;
	}
	else {
		std::cout << "Error: can\'t open the file!\n";
	}
	app_file.close();
}

// Writes a new file or rewrites the existing file
void WriteTextFile(const std::string kFileName, const std::string kText) {
	std::ofstream out_file(kFileName, std::ios::out | std::ios::trunc);
	if (out_file.is_open()) {
		out_file << kText;
	}
	else {
		std::cout << "Error: can\'t open the file!\n";
	}
	out_file.close();
}

// Returns the text typed by the user
std::string GetText() {
	const char kBreakChar = static_cast <char> (23);
	bool proceed_typing{ true };
	std::string text;
	while (proceed_typing) {
		std::string current_line{};
		getline(std::cin, current_line);

		if (current_line.find_first_of(kBreakChar) != std::string::npos) {
			size_t break_pos = current_line.find_first_of(kBreakChar);
			if (break_pos) {
				text += current_line.substr(0, break_pos) + "\n";
			}
			proceed_typing = false;
		}
		else {
			text += current_line + "\n";
		}
	}
	return text;
}

// Returns true if the file can be opened and false if not
bool IsFileAccessible(const std::string kFileName) {
	bool file_is_accessible{};
	std::ifstream in_file(kFileName, std::ios::in);
	if (in_file.is_open()) {
		file_is_accessible = true;
	}
	else {
		file_is_accessible = false;
	}
	in_file.close();
	return file_is_accessible;
}

// User interface for working with the source text file
void SourceFileProcessing(const std::string kFileName) {
	bool source_file_is_conditional{ false };
	while (!source_file_is_conditional) {
		bool source_file_already_exists = IsFileAccessible(kFileName);
		std::string text{};
		if (source_file_already_exists) {
			PrintFileContent(kFileName, "The content of the source text file now:");
			char mode{};
			bool mode_is_correct{ false };

			while (!mode_is_correct) {
				std::cout << "Please, choose one option (rewrite file - r | extend file - e | do nothing - n): ";
				std::cin >> mode;
				switch (mode) {
				case 'r':
					std::cin.ignore();
					std::cout << "Please, enter the text of the file (enter CTRL + W to stop typing):\n";
					text = GetText();
					WriteTextFile(kFileName, text);
					mode_is_correct = true;
					break;
				case 'e':
					std::cin.ignore();
					std::cout << "Please, enter the text to extend the existing file (enter CTRL + W to stop typing):\n";
					text = GetText();
					AppendTextToFile(kFileName, text);
					mode_is_correct = true;
					break;
				case 'n':
					mode_is_correct = true;
					break;
				default:
					std::cout << "Error: entered character is not correct, enter another one.\n";
					break;
				}
			}
		}
		else {
			std::cout << "There is no existing source file, you should type one. Enter CTRL + W to stop typing.\n";
			text = GetText();
			WriteTextFile(kFileName, text);
		}

		source_file_is_conditional = IsSourceFileConditional(kFileName);
		if (!source_file_is_conditional) {
			std::cout << "\nSource file is not conditional now. It should be changed.\n";
		}
	}
}

// Forms new text file based on source text file
void NewFileForming(std::string kSourceFileName, std::string kNewFileName) {
	std::ifstream in_file(kSourceFileName, std::ios::in);
	std::ofstream out_file(kNewFileName, std::ios::out | std::ios::trunc);
	std::string first_part{}, second_part{};
	const char kConditionalChar{ '#' }, kInsertChar{ '!' };
	while (!in_file.eof()) {
		std::string current_line{};
		getline(in_file, current_line);
		if (current_line.length()) {
			if (current_line.at(0) != kConditionalChar) {
				first_part += current_line + "\n";
			}
			else {
				std::string insert_line = current_line.substr(1);
				size_t insert_pos = insert_line.length() / 2;
				insert_line.insert(insert_pos, 1, kInsertChar);
				second_part += insert_line + "\n";
			}
		}
	}
	std::string new_file_text = first_part += second_part;
	out_file << new_file_text;
	in_file.close();
	out_file.close();
}