#include <iostream>
#include <cstdlib>
#include <ctime>

// Returns random real number from -100.0 to 100.0.
float generateRandomRealNum();

// Generates an array of random real numbers. The size of array is entered by the user. 
// Returns the entered array size and the generated array.
float* generateRandomArray(int &arrSize);

// Outputs the elements of an array.
void arrOutput(float* arr, int arrSize);

int main()
{
    srand(static_cast <unsigned int> (time(NULL)));
    int arrBSize;
    float* arrB = generateRandomArray(arrBSize);;
    arrOutput(arrB, arrBSize);
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
    std::cout << "Enter the size of array: ";
    std::cin >> arrSize;

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