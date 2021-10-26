/*
* Variant 2. Program to find the sum of n elements of the series
*/

#include <iostream>
#include <math.h>
#include <iomanip>

//Returns the Nth element of the series.  
float findNthElement(unsigned short n);

//Returns the sum of elements from 1 to nth
float findSeriesSum(unsigned short n);

int main()
{
    unsigned short n; //the number of elemnts, sum of which will be calculated
    std::cout << "Please, input natural number N: ";
    std::cin >> n;

    float seriesSum;
    seriesSum = findSeriesSum(n);

    std::cout << "Sum of the elements: " << std::fixed << std::setprecision(10) << seriesSum << "\n";
    system("pause");
    return 0;
}

//Returns the sum of elements of the series from 1 to n
float findSeriesSum(unsigned short n)
{
    float seriesSum(0);
    float currentElem;
    for (unsigned short i = 1; i <= n; ++i)
    {
        currentElem = findNthElement(i);
        seriesSum += currentElem;
    }
    return seriesSum;
}

//Returns the Nth element of the series.  
float findNthElement(unsigned short n)
{
    float NthElement;
    NthElement = 1. / (n * pow(2 * n + 1, 2));
    return NthElement;
}