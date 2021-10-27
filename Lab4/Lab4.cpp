/*
* Variant 2. Program to find the sum of n elements of the series
*/

#include <iostream>
#include <math.h>
#include <iomanip>

//Returns the Nth element of the series
long double findNthElement(unsigned long long n);

//Returns the sum of elements from 1 to nth
long double findSeriesSum(unsigned long long n);

int main()
{
    unsigned long long n; //the number of elemnts, sum of which will be calculated
    std::cout << "Please, input natural number N: ";
    std::cin >> n;

    long double seriesSum;
    seriesSum = findSeriesSum(n);
    std::cout << "Sum of the elements: " << std::fixed << std::setprecision(15) << seriesSum << "\n";

    system("pause");
    return 0;
}

//Returns the sum of elements of the series from 1 to n
long double findSeriesSum(unsigned long long n)
{
    long double seriesSum(0);
    long double currentElem;
    for (unsigned long long i = 1; i <= n; ++i)
    {
        currentElem = findNthElement(i);
        seriesSum += currentElem;
    }
    return seriesSum;
}

//Returns the Nth element of the series
long double findNthElement(unsigned long long n)
{
    long double NthElement;
    NthElement = 1. / (n * pow(2 * n + 1, 2));
    return NthElement;
}