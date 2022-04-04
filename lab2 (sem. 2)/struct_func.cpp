#include "struct_func.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

bool IsLeapYear(int year) {
	bool year_is_leap{ false };

	if ((year % 100 == 0 && year % 400 == 0) || (year % 100 != 0 && year % 4 == 0)) {
		year_is_leap = true;
	}

	return year_is_leap;
}

bool IsDatePossible(Date curr) {
	bool date_is_possible{ false };

	if (curr.day > 0 && curr.month > 0 && curr.year > 0 && curr.month <= NUM_OF_MONTHS) {
		bool year_is_leap = IsLeapYear(curr.year);
		if (curr.day <= DAYS_PER_MONTH[curr.month - 1] || (year_is_leap && curr.month == FEB_SEQUENCE_NUM &&
			curr.day <= LEAP_MONTH_DAYS_NUM)) {
			date_is_possible = true;
		}
	}

	return date_is_possible;
}

std::string DateToString(Date curr) {
	std::string strDate{};

	if (curr.day < 10) {
		strDate += "0" + std::to_string(curr.day) + SEP;
	}
	else {
		strDate += std::to_string(curr.day) + SEP;
	}

	if (curr.month < 10) {
		strDate += "0" + std::to_string(curr.month) + SEP;
	}
	else {
		strDate += std::to_string(curr.month) + SEP;
	}

	strDate += std::to_string(curr.year);

	return strDate;
}

int GetDaysNumberOfDate(Date curr) {
	int days_number{};
	days_number += ((curr.year - 1) * 365) + ((curr.year - 1) / 4) - ((curr.year - 1) / 100) +
		((curr.year - 1) / 400);

	for (int i{ 0 }; i < curr.month - 1; ++i) {
		days_number += DAYS_PER_MONTH[i];
		bool year_is_leap = IsLeapYear(curr.year);
		if (i == FEB_SEQUENCE_NUM - 1 && year_is_leap) {
			days_number++;
		}
	}
	days_number += curr.day;

	return days_number;
}

int GetDateDifferenceInDays(Date date1, Date date2) {
	int date_difference{};

	date_difference = GetDaysNumberOfDate(date1) - GetDaysNumberOfDate(date2);

	return date_difference;
}

Date StringToDate(std::string str_date) {
	Date curr_date{};
	const size_t FIRST_SEPARATOR_POS{ 2 }, SECOND_SEPARATOR_POS{ 5 };

	curr_date.day = std::stoi(str_date.substr(0, FIRST_SEPARATOR_POS));
	curr_date.month = std::stoi(str_date.substr(FIRST_SEPARATOR_POS + 1, SECOND_SEPARATOR_POS - FIRST_SEPARATOR_POS - 1));
	curr_date.year = std::stoi(str_date.substr(SECOND_SEPARATOR_POS + 1));

	return curr_date;
}

bool IsDecimalNumber(std::string current) {
	bool result{ true };

	for (size_t i{ 0 }; i < current.length() && result; ++i) {
		if (!isdigit(current.at(i))) {
			result = false;
		}
	}
	return result;
}

bool IsStringDatePossible(std::string str_date) {
	bool str_date_is_possible{ false };
	const size_t FIRST_SEPARATOR_POS{ 2 }, SECOND_SEPARATOR_POS{ 5 }, MIN_LENGTH{ 7 };

	if (str_date.length() >= MIN_LENGTH) {
		if (str_date.at(FIRST_SEPARATOR_POS) == SEP && str_date.at(SECOND_SEPARATOR_POS) == SEP) {
			if (IsDecimalNumber(str_date.substr(0, FIRST_SEPARATOR_POS)) &&
				IsDecimalNumber(str_date.substr(FIRST_SEPARATOR_POS + 1, SECOND_SEPARATOR_POS - FIRST_SEPARATOR_POS - 1)) &&
				IsDecimalNumber(str_date.substr(SECOND_SEPARATOR_POS + 1))) {
				str_date_is_possible = true;
			}
		}
	}
	return str_date_is_possible;
}

std::vector <Product> GetContent(std::string current_date) {
	int number_of_items = 0;
	while (number_of_items <= 0) {
		std::cout << "Please, enter the number of products in the store: ";
		std::cin >> number_of_items;
		if (number_of_items <= 0) {
			std::cerr << "\nError: the number of items should be positive! Enter another one.\n";
		}
	}

	std::cout << "\nPlease, enter the list of products. Each line should contain name, date of manufacture and expiration date " <<
		"\n(product name should contain less than 100 symbols, date format is DD-MM-YYYY):\n";

	std::vector <Product> products_list;
	int i{ 0 };

	while (i < number_of_items) {
		std::string curr_str_manufacture_date{}, curr_str_expiration_date{}, curr_product_name{};

		std::cin >> curr_product_name >> curr_str_manufacture_date >> curr_str_expiration_date;
		if (!IsStringDatePossible(curr_str_manufacture_date) || !IsStringDatePossible(curr_str_expiration_date) ||
			curr_product_name.size() >= NAME_MAX_LENGTH) {
			std::cerr << "\nError: format of entered dates are not correct! Enter another line.\n";
		}
		else {
			Date curr_manufacture_date = StringToDate(curr_str_manufacture_date);
			Date curr_expiration_date = StringToDate(curr_str_expiration_date);
			if (!IsDatePossible(curr_manufacture_date) || !IsDatePossible(curr_expiration_date) ||
				GetDateDifferenceInDays(curr_expiration_date, curr_manufacture_date) < 0 ||
				GetDaysNumberOfDate(curr_manufacture_date) > GetDaysNumberOfDate(StringToDate(current_date))) {
				std::cerr << "\nError: entered dates are impossible! Enter another line.\n";
			}
			else {
				Product curr_product;
				strcpy_s(curr_product.product_name, curr_product_name.c_str());
				curr_product.manufacture_date = curr_manufacture_date;
				curr_product.expiration_date = curr_expiration_date;
				products_list.push_back(curr_product);
				i++;
			}
		}
	}

	return products_list;
}

int GetStorageDaysNumber(Product curr) {
	int storage_days_number{};

	storage_days_number = GetDateDifferenceInDays(curr.expiration_date, curr.manufacture_date);

	return storage_days_number;
}

void PrintProductsList(std::vector <Product> products_list) {
	for (size_t i{ 0 }; i < products_list.size(); ++i) {
		std::cout << products_list[i].product_name << '\t' << DateToString(products_list[i].manufacture_date) <<
			'\t' << DateToString(products_list[i].expiration_date) << '\n';
	}
}

std::vector <Product> GetLongTermStorageProducts(std::vector <Product> products_list) {
	const int COND_NUM = 5;
	std::vector <Product> long_term_products;

	for (int i{ 0 }; i < products_list.size(); ++i) {
		int curr_storage_days_number = GetStorageDaysNumber(products_list[i]);
		if (curr_storage_days_number > COND_NUM) {
			long_term_products.push_back(products_list[i]);
		}
	}

	return long_term_products;
}

std::vector <Product> GetShortTermStorageProducts(std::vector <Product> products_list) {
	const int COND_NUM = 5;
	std::vector <Product> short_term_products;

	for (int i{ 0 }; i < products_list.size(); ++i) {
		int curr_storage_days_number = GetStorageDaysNumber(products_list[i]);
		if (curr_storage_days_number <= COND_NUM) {
			short_term_products.push_back(products_list[i]);
		}
	}

	return short_term_products;
}

void DeleteExpiredProducts(std::vector <Product>& products_list, Date current_date) {
	int i{ 0 };

	while (i < products_list.size()) {
		if (GetDateDifferenceInDays(products_list[i].expiration_date, current_date) < 0) {
			products_list.erase(products_list.begin() + i);
		}
		else {
			i++;
		}
	}
}
