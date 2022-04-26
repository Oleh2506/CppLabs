// variant 2

#include <iostream>
#include "Point.h"
#include "StraightLine.h"

int main()
{
	StraightLine p1{ -2.0, 1.0, 0.0 }, p2{ Point{ 1.0, 0.0 }, Point{ 2.0, 2.0 } }, p3;
	p1.print("p1");
	p2.print("p2");
	p3.print("p3");

	if (p1 || p2) {
		std::cout << "p1 and p2 are parallel\n";
	}
	else {
		std::cout << "p1 and p2 aren\'t parallel\n";
	}

	Point p3IntersectionPointOX{ p3.getIntersectionPointOX() }, p3IntersectionPointOY{ p3.getIntersectionPointOY() };
	p3IntersectionPointOX.print("p3\'s OX intersection point before rotating");
	p3IntersectionPointOY.print("p3\'s OY intersection point before rotating");

	p3++;
	p3.print("p3 after rotating");

	p3IntersectionPointOX = p3.getIntersectionPointOX();
	p3IntersectionPointOY = p3.getIntersectionPointOY();
	p3IntersectionPointOX.print("p3\'s OX intersection point after rotating");
	p3IntersectionPointOY.print("p3\'s OY intersection point after rotating");

	return 0;
}
