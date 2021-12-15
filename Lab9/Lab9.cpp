// Variant 2.

#include <iostream>
#include <string>

// Returns the sum of numbers from entered str if it contains digits and spaces only
// and -1 if not.
int findSum(std::string str);

// Returns true if entered str contains characters from alphabet only and false if not. 
bool isStrCorrect(std::string str, std::string alphabet);

int main()
{
	std::string str{};
	std::cout << "Enter the string that contains digits and spaces: ";
	std::getline(std::cin, str);

	const std::string DIGITS{ "0123456789" }, DELIMITER{ " " };
	bool strIsCorrect{ isStrCorrect(str, DIGITS + DELIMITER) };
	if (strIsCorrect) {
		int sum{};
		sum = findSum(str);
		std::cout << "\nThe sum of numbers is: " << sum << "\n";
	}
	else {
		std::cout << "\nError: input string contains unconditional characters!\n";
	}
	return 0;
}

// Returns true if entered str contains characters from alphabet only and false if not. 
bool isStrCorrect(std::string str, std::string alphabet)
{
	bool strIsCorrect{ true };
	for (size_t i{ 0 }; i < str.length() && strIsCorrect; ++i) {
		if (alphabet.find(str.at(i)) == std::string::npos) {
			strIsCorrect = false;
		}
	}
	return strIsCorrect;
}

// Returns the sum of numbers from entered str if it contains digits and spaces only
// and -1 if not.
int findSum(std::string str)
{
	int sum{};
	const std::string DIGITS{ "0123456789" }, DELIMITER{ " " };
	if (isStrCorrect(str, DIGITS + DELIMITER)) {
		// Forming strToProcess that consists of one space at the beginning, words separated by spaces
		// and one space at the end based on str.
		std::string strToProcess = DELIMITER + str;
		size_t strToProcessLastPos = strToProcess.length() - 1;
		// Erasing spaces at the end of strToProcess. 
		if (strToProcess.at(strToProcessLastPos) == ' ') {
			strToProcess.erase(strToProcess.find_last_of(DIGITS) + 1);
		}
		strToProcess += DELIMITER;
		strToProcessLastPos = strToProcess.length() - 1;

		// Calculating the sum of numbers from entered str.
		std::string currentWord{};
		int currentNum{};
		size_t wordBeginningPos{}, wordLength{}, spacePos{};
		while (spacePos != strToProcessLastPos) {
			wordBeginningPos = strToProcess.find_first_of(DIGITS, spacePos);
			spacePos = strToProcess.find_first_not_of(DIGITS, wordBeginningPos);
			wordLength = spacePos - wordBeginningPos;
			currentWord = strToProcess.substr(wordBeginningPos, wordLength);
			currentNum = std::stoi(currentWord);
			sum += currentNum;
		}
	}
	else {
		sum = -1;
	}
	return sum;
}
