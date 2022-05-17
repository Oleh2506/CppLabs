#include "ArithmeticSequence.h"
#include <cassert>

double ArithmeticSequence::getNthTerm(int n) const {
	assert(n > 0);

	double nthTerm = firstTerm_ + commonDifference_ * (n - 1.0);

	return nthTerm;
}


double ArithmeticSequence::getSumOfNTerms(int n) const {
	assert(n > 0);

	double sumOfNTerms = (firstTerm_ + getNthTerm(n)) * n / 2;

	return sumOfNTerms;
}

ArithmeticSequence::ArithmeticSequence(double firstTerm, double commonDifference) : commonDifference_{ commonDifference }, TSeries( firstTerm ) {}

ArithmeticSequence::ArithmeticSequence() : commonDifference_{ 0.0 }, TSeries( 0.0 ) {}

void ArithmeticSequence::setFirstTerm(double firstTerm) { firstTerm_ = firstTerm; }

double ArithmeticSequence::getFirstTerm() const { return firstTerm_; }

void ArithmeticSequence::setCommonDifference(double commonDifference) { commonDifference_ = commonDifference; }

double ArithmeticSequence::getCommonDifference() const { return commonDifference_; }

