#include "Point.h"

Point::Point() : x_{ 0.0 }, y_{ 0.0 } { }

Point::Point(const double x, const double y) : x_{ x }, y_{ y } { }

Point::Point(const Point& curr) {
	x_ = curr.x_;
	y_ = curr.y_;
}

double Point::getX() { return x_; }

double Point::getY() { return y_; }

void Point::setX(double x) { x_ = x; }

void Point::setY(double y) { y_ = y; }

Point::~Point() { }

void Point::rotate(double angleInRadians, Point currOrigin) {
	x_ = (x_ - currOrigin.getX()) * cos(angleInRadians) - (y_ - currOrigin.getY()) * sin(angleInRadians) 
		+ currOrigin.getX();

	y_ = (x_ - currOrigin.getX()) * sin(angleInRadians) + (y_ - currOrigin.getY()) * cos(angleInRadians)
		+ currOrigin.getY();
}

void Point::print(const std::string pointsName) {
	std::cout << pointsName << " : (" << x_ << "; " << y_ << ")\n";
}