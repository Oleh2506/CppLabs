#pragma once

#define _USE_MATH_DEFINES

#include "Point.h"
#include <cmath>
#include <stdexcept>
#include <string>
#include <iostream>

class StraightLine {
private:
	double a_, b_, c_;

	Point findIntersectionPointOX();
	Point findIntersectionPointOY();
public:
	StraightLine();
	StraightLine(double, double, double);
	StraightLine(Point, Point);
	StraightLine(const StraightLine&);
	void print(const std::string);
	void setA(double);
	void setB(double);
	void setC(double);
	double getA();
	double getB();
	double getC();
	Point getIntersectionPointOX();
	Point getIntersectionPointOY();
	friend bool operator||(const StraightLine&, const StraightLine&);
	StraightLine& operator++();
	StraightLine operator++(int);
	~StraightLine();
};