#include "StraightLine.h"

StraightLine::StraightLine() : a_{ 1.0 }, b_{ 0.0 }, c_{ 0.0 } { }

StraightLine::StraightLine(double a, double b, double c) {
	if ((a == 0.0) && (a == b)) {
		throw std::invalid_argument("Invalid arguments received!");
	}
	else {
		a_ = a;
		b_ = b;
		c_ = c;
	}
}

StraightLine::StraightLine(const StraightLine& curr) {
	a_ = curr.a_;
	b_ = curr.b_;
	c_ = curr.c_;
}

StraightLine::StraightLine(Point p1, Point p2) {
	a_ = p2.getY() - p1.getY();
	b_ = p1.getX() - p2.getX();
	c_ = p1.getY() * (p2.getX() - p1.getX()) - p1.getX() * (p2.getY() - p1.getY());
}

void StraightLine::setA(double a) { a_ = a; }

void StraightLine::setB(double b) { b_ = b; }

void StraightLine::setC(double c) { c_ = c; }

Point StraightLine::findIntersectionPointOX() {
	double x{}, y{};

	if (a_ != 0.0) {
		x = -c_ / a_;
	}
	else {
		x = HUGE_VAL;
	}

	Point intersectionPointOX{ x, y };
	return intersectionPointOX;
}

Point StraightLine::findIntersectionPointOY() {
	double x{}, y{};

	if (b_ != 0.0) {
		y = -c_ / b_;
	}
	else {
		y = HUGE_VAL;
	}

	Point intersectionPointOY{ x, y };
	return intersectionPointOY;
}

double StraightLine::getA() { return a_; }

double StraightLine::getB() { return b_; }

double StraightLine::getC() { return c_; }

Point StraightLine::getIntersectionPointOX() {
	Point intersectionPointOX;

	intersectionPointOX = findIntersectionPointOX();

	return intersectionPointOX;
}

Point StraightLine::getIntersectionPointOY() {
	Point intersectionPointOY;

	intersectionPointOY = findIntersectionPointOY();

	return intersectionPointOY;
}

bool operator||(const StraightLine& line1, const StraightLine& line2) {
	bool result{ false };

	if ((line1.a_ / line2.a_ == line1.b_ / line2.b_ && line1.a_ / line2.a_ != line1.c_ / line2.c_)
		|| (line1.a_ == 0.0 && line2.a_ == 0.0 && line1.c_ / line1.b_ != line2.c_ / line2.b_)
		|| (line1.b_ == 0.0 && line2.b_ == 0.0 && line1.c_ / line1.a_ != line2.c_ / line2.a_)) {
		result = true;
	}
	else {
		result = false;
	}

	return result;
}

StraightLine& StraightLine::operator++() {
	Point p1, p2;
	if (a_ == 0.0) {
		p1 = getIntersectionPointOY();
		p2.setX(1.0);
		p2.setY(-c_ / b_);
	}
	else {
		if (b_ == 0.0) {
			p1 = getIntersectionPointOX();
			p2.setX(-c_ / a_);
			p2.setY(1.0);
		}
		else {
			p1 = getIntersectionPointOX();
			p2.setX(-(b_ + c_) / a_);
			p2.setY(1.0);
		}
	}

	Point origin(0.0, 0.0);
	p1.rotate(-M_PI / 180.0, origin);
	p2.rotate(-M_PI / 180.0, origin);
	
	StraightLine rotatedLine(p1, p2);
	a_ = rotatedLine.getA();
	b_ = rotatedLine.getB();
	c_ = rotatedLine.getC();

	return *this;
}

StraightLine StraightLine::operator++(int) {
	StraightLine temp(*this);
	++(*this);

	return temp;
}

void StraightLine::print(const std::string linesName) {
	std::cout << linesName << " : ";
	if (a_ < 0) {
		std::cout << "(" << a_ << ") * x + ";
	}
	else {
		std::cout << a_ << " * x + ";	
	}

	if (b_ < 0) {
		std::cout << "(" << b_ << ") * y + ";
	}
	else {
		std::cout << b_ << " * y + ";	
	}

	if (c_ < 0) {
		std::cout << "(" << c_ << ")";
	}
	else {
		std::cout << c_;
	}

	std::cout << " = 0\n";
}

StraightLine::~StraightLine() { }