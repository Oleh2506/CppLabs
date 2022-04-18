#pragma once

#define _USE_MATH_DEFINES

#include <cmath>
#include <string>
#include <iostream>

class Point {
private:
	double x_, y_;
public:
	Point();
	Point(const double, const double);
	Point(const Point&);
	double getX();
	double getY();
	void setX(double);
	void setY(double);
	void rotate(double, Point);
	void print(const std::string);
	~Point();
};