// Variant 2.

#include <iostream>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
#include <iomanip>  // setw()

// Returns random integer number from -100 to 100.
int getRandomNum();

// Generates two-dimensional array of random integer numbers. 
// The row number and the column number is variable n. It is entered by the user.
// Returns entered n and the generated array.
int** generateRandom2DArray(int& arrSize);

// Outputs the elements of two-dimensional array[rowNum x colNum].
void twoDimensionalArrayOutput(int **arr, int rowNum, int colNum);

// Deletes two-dimensional dynamic array.
void deleteTwoDimensionalArray(int** arr, int rowNum);

// Generates two-dimensional array B[n][n] based on two-dimensional array A[n][n] 
// according to the task. Returns array B[n][n].
int** generateArrayB(int** arrA, int n);

int main()
{
    int** arrA, n;
    arrA = generateRandom2DArray(n);
    std::cout << "\nArray A:\n";
    twoDimensionalArrayOutput(arrA, n, n);

    int** arrB;
    arrB = generateArrayB(arrA, n);
    deleteTwoDimensionalArray(arrA, n);
    std::cout << "\nArray B:\n";
    twoDimensionalArrayOutput(arrB, n, n);
    deleteTwoDimensionalArray(arrB, n);
    return 0;
}

// Returns random integer number from -100 to 100.
int getRandomNum()
{
    int randomNum;
    const int MY_RAND_MAX = 100, MY_RAND_MIN = -100;
    randomNum = MY_RAND_MIN + rand() % (MY_RAND_MAX - MY_RAND_MIN + 1);
    return randomNum;
}

// Generates two-dimensional array of random integer numbers. 
// The row number and the column number is variable n. It is entered by the user.
// Returns entered n and the generated array.
int** generateRandom2DArray(int& n)
{
    do
    {
        std::cout << "Enter N that is the row number and the column number of array[N x N]: ";
        std::cin >> n;
        if (n <= 0)
        {
            std::cout << "Error: input number can not be row number and the column number of array[N x N].\nPlease, enter another one.\n";
        }
    } while (n <= 0);

    srand(static_cast <unsigned int> (time(NULL)));

    int** arr = new int* [n];
    for (int i = 0; i < n; ++i)
    {
        arr[i] = new int [n];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            arr[i][j] = getRandomNum();
        }
    }
    return arr;
}

// Outputs the elements of two-dimensional array[rowNum x colNum].
void twoDimensionalArrayOutput(int** arr, int rowNum, int colNum)
{
    std::cout << "\nElements of two-dimensional array:\n";
    for (int i = 0; i < rowNum; ++i)
    {
        for (int j = 0; j < colNum; ++j)
        {
            std::cout << std::setw(8) << arr[i][j];
        }
        std::cout << '\n';
    }
}

// Deletes two-dimensional dynamic array.
void deleteTwoDimensionalArray(int** arr, int rowNum)
{
    for (int i = 0; i < rowNum; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

// Generates two-dimensional array B[n][n] based on two-dimensional array A[n][n] 
// according to the task. Returns array B[n][n].
int** generateArrayB(int** arrA, int n)
{
    int** arrB = new int* [n];
    for (int i = 0; i < n; ++i)
    {
        arrB[i] = new int[n];
    }

    int tempMax, flagL, flagR;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            tempMax = arrA[i][j];
            flagL = flagR = j;
            for (int k = i + 1; k < n; ++k)
            {
                flagL = ((flagL > 0) ? flagL - 1 : 0);
                flagR = ((flagR < (n - 1)) ? flagR + 1 : (n - 1));
                for (int t = flagL; t <= flagR; ++t)
                {
                    if (tempMax < arrA[k][t])
                    {
                        tempMax = arrA[k][t];
                    }
                }
            }
            arrB[i][j] = tempMax;
        }
    }
    return arrB;
}