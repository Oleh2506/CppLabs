#include <iostream>
#include "Quadrangle.h"
#include "MyFunc.h"
#include "Point.h"

int main() {
	const size_t NUMBER_OF_QUADRANGLES{ 10 };
	Quadrangle* quadranglesArray = new Quadrangle[NUMBER_OF_QUADRANGLES];

	fillRandomQuadrangleArray(quadranglesArray, NUMBER_OF_QUADRANGLES);

	printQuadrangleArray(quadranglesArray, NUMBER_OF_QUADRANGLES);

	float maxP = getMaxPerimeter(quadranglesArray, NUMBER_OF_QUADRANGLES);

	std::cout << "\nMax perimeter is: " << maxP << "\n";

	delete[] quadranglesArray;
	return 0;
}
