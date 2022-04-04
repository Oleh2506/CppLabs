#pragma once

#include <string>
#include <vector>

const int NUM_OF_MONTHS{ 12 };
const int DAYS_PER_MONTH[NUM_OF_MONTHS]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int FEB_SEQUENCE_NUM{ 2 };
const int LEAP_MONTH_DAYS_NUM{ 29 };
const char SEP{ '-' };
const int NAME_MAX_LENGTH{ 100 };

struct Date {
	int day{}, month{}, year{};
};

struct Product {
	char product_name[NAME_MAX_LENGTH]{};
	Date manufacture_date{}, expiration_date{};
};

bool IsLeapYear(int year);

bool IsDatePossible(Date curr);

std::string DateToString(Date curr);

int GetDaysNumberOfDate(Date curr);

int GetDateDifferenceInDays(Date date1, Date date2);

Date StringToDate(std::string str_date);

bool IsDecimalNumber(std::string current);

bool IsStringDatePossible(std::string str_date);

std::vector <Product> GetContent(std::string current_date);

int GetStorageDaysNumber(Product curr);

void PrintProductsList(std::vector <Product> products_list);

void DeleteExpiredProducts(std::vector <Product>& products_list, Date current_date);

std::vector <Product> GetShortTermStorageProducts(std::vector <Product> products_list);

std::vector <Product> GetLongTermStorageProducts(std::vector <Product> products_list);