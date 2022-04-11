#include "Quadrangle.h"
#include "MyFunc.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>

void Quadrangle::calculatePerimeter() {
	perimeter_ = 0;
	for (size_t i{ 0 }; i < QUADRANGLE_SIDES_NUMBER; ++i) {
		perimeter_ += sidesLengths_[i];
	}
}

void Quadrangle::calculateSidesLengths() {
	for (size_t i{ 0 }; i < QUADRANGLE_SIDES_NUMBER; ++i) {
		if (i + 1 != QUADRANGLE_SIDES_NUMBER) {
			sidesLengths_[i] = getSegmentLength(consecutiveVertices_[i], consecutiveVertices_[i + 1]);
		}
		else {
			sidesLengths_[i] = getSegmentLength(consecutiveVertices_[i], consecutiveVertices_[0]);
		}
	}
}

Quadrangle::Quadrangle(Point pointsArr[QUADRANGLE_VERTICES_NUMBER]) {
	validateInputData(pointsArr);
	
	calculateSidesLengths();
	
	calculatePerimeter();
}

float Quadrangle::getPerimeter() { return perimeter_; }

void Quadrangle::validateInputData(Point pointsArr[QUADRANGLE_VERTICES_NUMBER]) {
	Point currPointsArr[QUADRANGLE_VERTICES_NUMBER]{};
	bool convex{ false };

	for (size_t i{ 0 }; i < QUADRANGLE_VERTICES_NUMBER && !convex; ++i) {
		for (size_t j{ 0 }; j < QUADRANGLE_VERTICES_NUMBER && !convex; ++j) {
			if (i != j) {
				for (size_t k{ 0 }; k < QUADRANGLE_VERTICES_NUMBER && !convex; ++k) {
					if (i != k && j != k) {
						for (size_t q{ 0 }; q < QUADRANGLE_VERTICES_NUMBER && !convex; ++q) {
							if (q != i && q != j && q != k) {
								currPointsArr[0] = pointsArr[i];
								currPointsArr[1] = pointsArr[j];
								currPointsArr[2] = pointsArr[k];
								currPointsArr[3] = pointsArr[q];

								convex = isQuadrangleConvex(currPointsArr);
							}
							else {
								continue;
							}
						}
					}
					else {
						continue;
					}
				}
			}
			else {
				continue;
			}
		}
	}
	if (convex) {
		for (size_t i{ 0 }; i < QUADRANGLE_VERTICES_NUMBER; ++i) {
			consecutiveVertices_[i] = currPointsArr[i];
		}
	}
	else {
		for (size_t i{ 0 }; i < QUADRANGLE_VERTICES_NUMBER; ++i) {
			consecutiveVertices_[i].setX(0.0);
			consecutiveVertices_[i].setY(0.0);
		}
	}
}

float Quadrangle::getSegmentLength(Point p1, Point p2) {
	float segment{};

	segment = sqrt(pow(p2.getX() - p1.getX(), 2.0) + pow(p2.getY() - p1.getY(), 2.0));

	return segment;
}

float Quadrangle::getLineEquation(Point p0, Point p1, Point p2) {
	float value{};
	value = (p0.getX() - p1.getX()) * (p2.getY() - p1.getY()) - (p0.getY() - p1.getY())
		* (p2.getX() - p1.getX());
	return value;
}

bool Quadrangle::isQuadrangleConvex(Point consecutiveVertices[QUADRANGLE_VERTICES_NUMBER]) {
	bool quadrangleIsConvex{ false };
	const size_t N{ 8 };
	float v[N];

	v[0] = getLineEquation(consecutiveVertices[2], consecutiveVertices[1], consecutiveVertices[0]);
	v[1] = getLineEquation(consecutiveVertices[3], consecutiveVertices[1], consecutiveVertices[0]);
	v[2] = getLineEquation(consecutiveVertices[0], consecutiveVertices[2], consecutiveVertices[1]);
	v[3] = getLineEquation(consecutiveVertices[3], consecutiveVertices[2], consecutiveVertices[1]);
	v[4] = getLineEquation(consecutiveVertices[0], consecutiveVertices[3], consecutiveVertices[2]);
	v[5] = getLineEquation(consecutiveVertices[1], consecutiveVertices[3], consecutiveVertices[2]);
	v[6] = getLineEquation(consecutiveVertices[1], consecutiveVertices[0], consecutiveVertices[3]);
	v[7] = getLineEquation(consecutiveVertices[2], consecutiveVertices[0], consecutiveVertices[3]);

	if (v[0] * v[1] >= 0 && v[2] * v[3] >= 0 && v[4] * v[5] >= 0 && v[6] * v[7] >= 0) {
		quadrangleIsConvex = true;
	}
	else {
		quadrangleIsConvex = false;
	}

	return quadrangleIsConvex;
}

Quadrangle::Quadrangle() {
	for (size_t i{ 0 }; i < QUADRANGLE_VERTICES_NUMBER; ++i) {
		consecutiveVertices_[i].setX(0.0);
		consecutiveVertices_[i].setY(0.0);
	}

	calculateSidesLengths();

	calculatePerimeter();
}

void Quadrangle::printSidesLengths() {
	std::cout << "\nSides lengths are:" << std::fixed << std::setprecision(1);
	for (size_t i{ 0 }; i < QUADRANGLE_SIDES_NUMBER; ++i) {
		std::cout << "\t" << sidesLengths_[i];
	}
}

void Quadrangle::printPerimeter() {
	std::cout << "\nPerimeter is:\t" << std::fixed << std::setprecision(1) << perimeter_;
}

void Quadrangle::printConsecutiveVertices() {
	std::cout << "\nConsecutive vertices coordinates are:" << std::fixed << std::setprecision(1);
	for (size_t i{ 0 }; i < QUADRANGLE_SIDES_NUMBER; ++i) {
		std::cout << "\t(" << consecutiveVertices_[i].getX() << "; " << consecutiveVertices_[i].getY() << ")";
	}
}

void Quadrangle::printData() {
	printConsecutiveVertices();
	printSidesLengths();
	printPerimeter();
	std::cout << "\n";
}