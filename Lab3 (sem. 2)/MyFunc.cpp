#include "MyFunc.h"
#include "Quadrangle.h"
#include <random>
#include "Point.h"
#include <cmath>
#include  <iostream>

float getRandomFloatNumber() {
	const float MY_RANDOM_MAX{ 5.0 }, MY_RANDOM_MIN{ -5.0 };

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dist(MY_RANDOM_MIN, MY_RANDOM_MAX);

	return dist(gen);
}

void printQuadrangleArray(Quadrangle* quadranglesArray, size_t arrSize) {
	for (size_t i{ 0 }; i < arrSize; ++i) {
		std::cout << "\nQuadrangle num. " << i + 1 << ":";
		quadranglesArray[i].printData();
	}
}

float getMaxPerimeter(Quadrangle* quadranglesArray, size_t arrSize) {
	float maxP{ 0 };
	for (size_t i{ 0 }; i < arrSize; ++i) {
		if (maxP < quadranglesArray[i].getPerimeter()) {
			maxP = quadranglesArray[i].getPerimeter();
		}
	}

	return maxP;
}

void fillRandomQuadrangleArray(Quadrangle* quadranglesArray, size_t arrSize) {
	for (size_t i{ 0 }; i < arrSize; ++i) {
		Point pointsArray[QUADRANGLE_VERTICES_NUMBER];

		for (size_t j{ 0 }; j < QUADRANGLE_VERTICES_NUMBER; ++j) {
			pointsArray[j].setX(getRandomFloatNumber());
			pointsArray[j].setY(getRandomFloatNumber());
		}

		Quadrangle currQ(pointsArray);
		quadranglesArray[i] = currQ;
	}
}