#pragma once

#include "ArithmeticSequence.h"
#include "GeometricSequence.h"
#include <vector>

double getRandomDouble();

void fillGeometricSequences(std::vector<GeometricSequence> &geometricSequences);

void fillArithmeticSequences(std::vector<ArithmeticSequence> &arithmeticSequences);

double findConditionalSum(const std::vector<GeometricSequence>& geometricSequences, const std::vector<ArithmeticSequence>& arithmeticSequences, int n, int m);

void printBaseInfo(const std::vector<GeometricSequence>& geometricSequences, const std::vector<ArithmeticSequence>& arithmeticSequences, int n, int m);
