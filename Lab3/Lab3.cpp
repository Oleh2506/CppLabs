// variant 2

/*
* Program to find natural logarithm using mathematical series
*/

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	float varA; //declaring a variable, the natural logarithm of which will be calculated

	cout << "Input variable \"a\" in the range (0;2]: ";
	cin >> varA;

	bool inputDataAreCorrect;      //declaring boolean variable that describes the correctness of input data
	if ((varA > 0) && (varA <= 2)) // checking the correctness of input data
	{
		inputDataAreCorrect = true;
	}
	else
	{
		inputDataAreCorrect = false;
	}

	if (inputDataAreCorrect)
	{
		float currentElem = varA - 1, lnA = 0, i = 0, percentError; //current element of the series, natural log of a, counter, percent error
		const float CALCULATION_ACCURACY = 0.000001;                // accuracy of calculation

		// finding the natural logarithm value
		do
		{
			lnA += currentElem;
			i++;
			currentElem *= ((-1) * (varA - 1) * i) / (i + 1);
		} while (abs(currentElem) > CALCULATION_ACCURACY);

		// percent error calculation
		if (varA != 1) 
		{
			percentError = (abs(lnA - log(varA)) / log(varA)) * 100;
		}
		else
		{
			percentError = 0;
		}

		cout << endl << fixed << setprecision(6) << "Ln(a): " << lnA << endl << "Percent error: " << percentError << " %" << endl; // result message output
	}
	else
	{
		cout << endl << "Error: input data aren't correct!" << endl; // error message output
	}

	return 0;
}
