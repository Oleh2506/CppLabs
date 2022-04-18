#include "Point.h"

Point::Point() : x_{ 0.0 }, y_{ 0.0 } { }

Point::Point(const float X, const float Y) : x_{ X }, y_{ Y } { }

float Point::getX() const { return x_; }

float Point::getY() const { return y_; }

void Point::setX(float x) { x_ = x; }

void Point::setY(float y) { y_ = y; }
