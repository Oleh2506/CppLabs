#include <iostream>
#include "ArithmeticSequence.h"
#include "GeometricSequence.h"

int main()
{
    ArithmeticSequence a{ 2.0, 3.0 };
    std::cout << a.getSumOfNTerms(4);
    return 0;
}