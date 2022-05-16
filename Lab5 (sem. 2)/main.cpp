// Variant 2

#include <iostream>
#include "ArithmeticSequence.h"
#include "GeometricSequence.h"
#include "Functions.h"
#include <vector>
#include <cassert>
#include <iomanip>

int main()
{
    int n;
    std::cout << "Enter n (n >= 2): ";
    std::cin >> n;
    assert(n >= 2);

    std::vector<ArithmeticSequence> arithmeticSequences(n / 2);
    std::vector<GeometricSequence> geometricSequences(n - n / 2);

    fillArithmeticSequences(arithmeticSequences);
    fillGeometricSequences(geometricSequences);

    int m;
    std::cout << "Enter m: ";
    std::cin >> m;
    assert(n > 0);

    double conditionalSum{};
    conditionalSum = findConditionalSum(geometricSequences, arithmeticSequences, n, m);
    std::cout << std::fixed << std::setprecision(1);
    printBaseInfo(geometricSequences, arithmeticSequences, n, m);
    std::cout << "Conditional sum is: " << conditionalSum;
    return 0;
}