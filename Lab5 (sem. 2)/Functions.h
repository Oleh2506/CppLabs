#pragma once

#include "ArithmeticSequence.h"
#include "GeometricSequence.h"
#include <vector>

double getRandomDouble();

void fillGeometricSequences(std::vector<GeometricSequence> &geometricSequences);

void fillArithmeticSequences(std::vector<ArithmeticSequence> &arithmeticSequences);

double findConditionalSum(std::vector<GeometricSequence> geometricSequences, std::vector<ArithmeticSequence> arithmeticSequences, int n, int m);

void printBaseInfo(std::vector<GeometricSequence> geometricSequences, std::vector<ArithmeticSequence> arithmeticSequences, int n, int m);
