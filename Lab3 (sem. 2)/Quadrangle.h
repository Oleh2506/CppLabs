#pragma once

#include "Point.h"

const size_t QUADRANGLE_VERTICES_NUMBER{ 4 }, QUADRANGLE_SIDES_NUMBER{ 4 };

class Quadrangle {
private:
	Point consecutiveVertices_[QUADRANGLE_VERTICES_NUMBER];
	float sidesLengths_[QUADRANGLE_SIDES_NUMBER];
	float perimeter_;

	void calculatePerimeter();
	void calculateSidesLengths();
	void validateInputData(Point[QUADRANGLE_VERTICES_NUMBER]);
	float getSegmentLength(Point, Point);
	float getLineEquation(Point, Point, Point);
	bool isQuadrangleConvex(Point[QUADRANGLE_VERTICES_NUMBER]);

public:
	void printSidesLengths();
	void printPerimeter();
	void printConsecutiveVertices();
	void printData();
	Quadrangle(Point[QUADRANGLE_VERTICES_NUMBER]);
	Quadrangle();
	float getPerimeter();
};