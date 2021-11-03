/*
* Variant 2. Program to find the sum of n elements of the series
*/

#include <iostream>
#include <math.h>
#include <iomanip>

//Returns the Nth element of the series
long double findNthElement(long long n);

//Returns the sum of elements from 1 to nth
long double findSeriesSum(long long n);

//Returns true if the number is positive and false if not
bool isPositiveNum(long long n);

int main()
{
    long long n; //the number of elemnts, sum of which will be calculated
    std::cout << "Please, input natural number N: ";
    std::cin >> n;

    bool isNaturalN;
    isNaturalN = isPositiveNum(n);
    if (isNaturalN)
    {
        long double seriesSum;
        seriesSum = findSeriesSum(n);
        // long double has a minimum precision of 15 significant digits
        std::cout << "Sum of the elements: " << std::fixed << std::setprecision(15) << seriesSum << "\n";
    }
    else
    {
        std::cout << "Error: input number is not natural!\n";
    }

    system("pause");
    return 0;
}

//Returns the sum of elements of the series from 1 to n
long double findSeriesSum(long long n)
{
    long double seriesSum(0);
    long double currentElem;
    for (long long i = 1; i <= n; ++i)
    {
        currentElem = findNthElement(i);
        seriesSum += currentElem;
    }
    return seriesSum;
}

//Returns the Nth element of the series
long double findNthElement(long long n)
{
    long double NthElement;
    NthElement = 1. / (n * pow(2 * n + 1, 2));
    return NthElement;
}

//Returns true if the number is positive and false if not
bool isPositiveNum(long long n)
{
    if (n > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}