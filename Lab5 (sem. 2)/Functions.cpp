#include "Functions.h"
#include <random>
#include <cmath>
#include  <iostream>
#include "ArithmeticSequence.h"
#include "GeometricSequence.h"
#include <vector>

double getRandomDouble() {
	const double MY_RANDOM_MAX{ 5.0 }, MY_RANDOM_MIN{ -5.0 };

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dist(MY_RANDOM_MIN, MY_RANDOM_MAX);

	return dist(gen);
}

void fillGeometricSequences(std::vector<GeometricSequence> &geometricSequences) {
	for (size_t i{ 0 }; i < geometricSequences.size(); ++i) {
		double currentRandom = getRandomDouble();
		geometricSequences.at(i).setFirstTerm(currentRandom);
		
		do {
			currentRandom = getRandomDouble();
		} while (currentRandom == 0.0);

		geometricSequences.at(i).setCommonRatio(currentRandom);
	}
}

void fillArithmeticSequences(std::vector<ArithmeticSequence> &arithmeticSequences) {
	for (size_t i{ 0 }; i < arithmeticSequences.size(); ++i) {
		double currentRandom = getRandomDouble();
		arithmeticSequences.at(i).setFirstTerm(currentRandom);

		currentRandom = getRandomDouble();
		arithmeticSequences.at(i).setCommonDifference(currentRandom);
	}
}

double findConditionalSum(const std::vector<GeometricSequence> &geometricSequences, const std::vector<ArithmeticSequence> &arithmeticSequences, int n, int m) {
	int maxIndexG{ 0 }, maxIndexA{ 0 };

	for (size_t i{ 1 }; i < arithmeticSequences.size(); ++i) {
		if (arithmeticSequences.at(i).getNthTerm(n) > arithmeticSequences.at(maxIndexA).getNthTerm(n)) {
			maxIndexA = i;
		}
	}

	for (size_t i{ 1 }; i < geometricSequences.size(); ++i) {
		if (geometricSequences.at(i).getNthTerm(n) > geometricSequences.at(maxIndexG).getNthTerm(n)) {
			maxIndexG = i;
		}
	}

	double conditionalSum{};

	if (geometricSequences.at(maxIndexG).getNthTerm(n) > arithmeticSequences.at(maxIndexA).getNthTerm(n)) {
		conditionalSum = geometricSequences.at(maxIndexG).getSumOfNTerms(m);
	}
	else {
		conditionalSum = arithmeticSequences.at(maxIndexA).getSumOfNTerms(m);
	}

	return conditionalSum;
}

void printBaseInfo(const std::vector<GeometricSequence> &geometricSequences, const std::vector<ArithmeticSequence> &arithmeticSequences, int n, int m) {
	for (size_t i{ 0 }; i < arithmeticSequences.size(); ++i) {
		std::cout << "AS(" << i << ").sum(" << m << ") = " << arithmeticSequences.at(i).getSumOfNTerms(m);
		std::cout << ", AS(" << i << ").commonDifference = " << arithmeticSequences.at(i).getCommonDifference();
		std::cout << ", AS(" << i << ").term(" << n << ") = " << arithmeticSequences.at(i).getNthTerm(n) << "\n";
	}

	for (size_t i{ 0 }; i < geometricSequences.size(); ++i) {
		std::cout << "GS(" << i << ").sum(" << m << ") = " << geometricSequences.at(i).getSumOfNTerms(m);
		std::cout << ", GS(" << i << ").commonRatio = " << geometricSequences.at(i).getCommonRatio();
		std::cout << ", GS(" << i << ").term(" << n << ") = " << geometricSequences.at(i).getNthTerm(n) << "\n";
	}
}