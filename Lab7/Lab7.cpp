// Variant 2. Program to generate an array B[n] and find largest and smallest 
// absolute values of the differences between neighbouring elements of the array

#include <iostream>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
#include <cmath>    // fabs()

// Returns random real number from -100.0 to 100.0.
float generateRandomRealNum();

// Generates an array of random real numbers. The size of array is entered by the user. 
// Returns the entered array size and the generated array.
float* generateRandomArray(int &arrSize);

// Outputs the elements of an array.
void arrOutput(float* arr, int arrSize);

// Returns largest absolute value of the difference between neighbouring elements of the array.
// arr[0] and arr[arrSize - 1] aren't neighbouring.
float findMaxAbsDif(float* arr, int arrSize);

// Returns smallest absolute value of the difference between neighbouring elements of the array.
// arr[0] and arr[arrSize - 1] aren't neighbouring.
float findMinAbsDif(float* arr, int arrSize);

// Outputs the result message.
void resMessageOutput(float maxAbsDif, float minAbsDif);

int main()
{
    srand(static_cast <unsigned int> (time(NULL)));

    int arrBSize;
    float* arrB = generateRandomArray(arrBSize);;
    arrOutput(arrB, arrBSize);

    float maxAbsDif, minAbsDif;
    maxAbsDif = findMaxAbsDif(arrB, arrBSize);
    minAbsDif = findMinAbsDif(arrB, arrBSize);

    resMessageOutput(maxAbsDif, minAbsDif);
    return 0;
}

// Returns random real number from -100.0 to 100.0.
float generateRandomRealNum()
{
    float randomRealNum;
    const float MY_RAND_MAX = 100.0, MY_RAND_MIN = -100.0;
    randomRealNum = MY_RAND_MIN + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (MY_RAND_MAX - MY_RAND_MIN)));
    return randomRealNum;
}

// Generates an array of random real numbers. The size of array is entered by the user. 
// Returns the entered array size and the generated array.
float* generateRandomArray(int &arrSize)
{
    float* arr;
    do
    {
        std::cout << "Enter the size of array: ";
        std::cin >> arrSize;
        if (arrSize <= 0)
        {
            std::cout << "Error: input number can not be the size of an array. Please, enter another one.\n";
        }
    } while (arrSize <= 0);

    arr = new float[arrSize];
    for (int i = 0; i < arrSize; ++i)
    {
        arr[i] = generateRandomRealNum();
    }

    return arr;
}

// Outputs the elements of an array.
void arrOutput(float* arr, int arrSize)
{
    std::cout << "\nElements of array:\n";
    for (int i = 0; i < arrSize; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

// Returns largest absolute value of the difference between neighbouring elements of the array.
// arr[0] and arr[arrSize - 1] aren't neighbouring.
float findMaxAbsDif(float* arr, int arrSize)
{
    float currentAbsDif, maxAbsDif = fabs(arr[1] - arr[0]); 
    for (int i = 2; i < arrSize; ++i)
    {
        currentAbsDif = fabs(arr[i] - arr[i - 1]);
        if (maxAbsDif < currentAbsDif)
        {
            maxAbsDif = currentAbsDif;
        }
    }
    return maxAbsDif;
}

// Returns smallest absolute value of the difference between neighbouring elements of the array.
// arr[0] and arr[arrSize - 1] aren't neighbouring.
float findMinAbsDif(float* arr, int arrSize)
{
    float currentAbsDif, minAbsDif = fabs(arr[1] - arr[0]);
    for (int i = 1; i < arrSize; ++i)
    {
        currentAbsDif = fabs(arr[i] - arr[i - 1]);
        if (minAbsDif > currentAbsDif)
        {
            minAbsDif = currentAbsDif;
        }
    }
    return minAbsDif;
}

// Outputs the result message.
void resMessageOutput(float maxAbsDif, float minAbsDif)
{
    std::cout << '\n';
    std::cout << "The largest absolute value of the difference between neighbouring elements of the array:\t" << maxAbsDif << '\n';
    std::cout << "The smallest absolute value of the difference between neighbouring elements of the array:\t" << minAbsDif << '\n';
}