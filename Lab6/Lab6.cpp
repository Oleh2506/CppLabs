// Variant 2. Program to find and compare the areas of three triangles.

#include <iostream>
#include <cmath>
#include <cstdarg>

// Returns the largest argument passed to the function; count -- the number of arguments
long double maxNum(long long count, ...);

// Returns true if the arguments passed to the function can be the sides of a triangle and false if not
bool areTriangleSides(long double side1, long double side2, long double side3);

// Returns the area of the triangle calculated by the formula of Heron if the sides values
// passed to the function are correct and 0 if not
long double heronsFormula(long double side1, long double side2, long double side3);

// Function to input the values of the sides of the triangle
// n -- is a sequence number of triangle
void sidesValuesInput(long long n, long double& side1, long double& side2, long double& side3);

// Prints the sequence numbers of triangles with largest areas and their areas in brackets; -1.0 -- an ellipsis control value
void resMessageOutput(long double maxArea, ...);

// Prints the error message
void errorMessageOutput();

int main()
{
    long double side11, side12, side13, side21, side22, side23, side31, side32, side33;
    sidesValuesInput(1, side11, side12, side13);
    sidesValuesInput(2, side21, side22, side23);
    sidesValuesInput(3, side31, side32, side33);

    bool inputDataAreCorrect;
    if (areTriangleSides(side11, side12, side13) && areTriangleSides(side21, side22, side23) &&
        areTriangleSides(side31, side32, side33))
    {
        inputDataAreCorrect = true;
    }
    else
    {
        inputDataAreCorrect = false;
    }

    if (inputDataAreCorrect)
    {
        long double area1, area2, area3;
        area1 = heronsFormula(side11, side12, side13);
        area2 = heronsFormula(side21, side22, side23);
        area3 = heronsFormula(side31, side32, side33);
        long double maxArea;
        maxArea = maxNum(3, area1, area2, area3);

        resMessageOutput(maxArea, area1, area2, area3, -1.0);
    }
    else
    {
        errorMessageOutput();
    }

    return 0;
}

// Returns the largest argument passed to the function; count -- the number of arguments
long double maxNum(long long count, ...)
{
    va_list list1;
    va_start(list1, count);
    long double maxArg, arg;
    maxArg = va_arg(list1, long double);
    
    for (long long i = 0; i < count - 1; ++i)
    {
        arg = va_arg(list1, long double);
        if (arg > maxArg)
        {
            maxArg = arg;
        }
    }
    va_end(list1);

    return maxArg;
}

// Returns true if the arguments passed to the function can be the sides of a triangle and false if not
bool areTriangleSides(long double side1, long double side2, long double side3)
{
    bool sidesAreCorrect;
    if ((side1 + side2 > side3) && (side1 + side3 > side2) && (side3 + side2 > side1))
    {
        sidesAreCorrect = true;
    }
    else
    {
        sidesAreCorrect = false;
    }
    return sidesAreCorrect;
}

// Returns the area of the triangle calculated by the formula of Heron if the sides values
// passed to the function are correct and 0 if not
long double heronsFormula(long double side1, long double side2, long double side3)
{
    bool sidesAreCorrect;
    sidesAreCorrect = areTriangleSides(side1, side2, side3);

    long double triangleArea;
    if (sidesAreCorrect)
    {
        long double semiperimeter;
        semiperimeter = (side1 + side2 + side3) / 2;
        triangleArea = sqrt(semiperimeter * (semiperimeter - side1) * (semiperimeter - side2) * (semiperimeter - side3));
    }
    else
    {
        triangleArea = 0;
    }
    return triangleArea;
}

// Function to input the values of the sides of the triangle
// n -- is a sequence number of triangle
void sidesValuesInput(long long n, long double& side1, long double& side2, long double& side3)
{
    std::cout << "Please, input the sides of triangle num. " << n << ":\n";
    std::cout << "Side 1: ";
    std::cin >> side1;
    std::cout << "Side 2: ";
    std::cin >> side2;
    std::cout << "Side 3: ";
    std::cin >> side3;
}

// Prints the sequence numbers of triangles with largest areas and their areas in brackets; -1.0 -- is an ellipsis control value
void resMessageOutput(long double maxArea, ...)
{
    va_list list1;
    va_start(list1, maxArea);
    int count = 1;

    while (count)
    {
        long double currentArea = va_arg(list1, long double);
        if (currentArea == -1)
        {
            break;
        }

        if (maxArea == currentArea)
        {
            std::cout << "The area of triangle num. " << count << " (" << currentArea << " sq.units) is the largest one.\n";
        }
        count++;
    }
    va_end(list1);
}

// Prints the error message
void errorMessageOutput()
{
    std::cout << "Error: input numbers aren\'t the sides of triangles!\n";
}