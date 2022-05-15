#include "ArithmeticSequence.h"

double ArithmeticSequence::calculateNthTerm(int n) const {
	double nthTerm = firstTerm_ + commonDifference_ * (n - 1.0);

	return nthTerm;
}


double ArithmeticSequence::calculateSumOfNTerms(int n) const {
	double sumOfNTerms = (firstTerm_ + calculateNthTerm(n)) * n / 2;

	return sumOfNTerms;
}

ArithmeticSequence::ArithmeticSequence(double firstTerm, double commonDifference) : firstTerm_{ firstTerm }, commonDifference_{ commonDifference }, TSeries() {}

ArithmeticSequence::ArithmeticSequence() : firstTerm_{ 0.0 }, commonDifference_{ 0.0 }, TSeries() {}

void ArithmeticSequence::setFirstTerm(double firstTerm) { firstTerm_ = firstTerm; }

double ArithmeticSequence::getFirstTerm() const { return firstTerm_; }

void ArithmeticSequence::setCommonDifference(double commonDifference) { commonDifference_ = commonDifference; }

double ArithmeticSequence::getCommonDifference() const { return commonDifference_; }

