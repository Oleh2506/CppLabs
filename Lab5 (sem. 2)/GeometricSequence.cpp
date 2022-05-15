#include "GeometricSequence.h"
#include <cassert>
#include <cmath>

double GeometricSequence::calculateNthTerm(int n) const {
	double nthTerm = firstTerm_ * pow(commonRatio_, n - 1);

	return nthTerm;
}


double GeometricSequence::calculateSumOfNTerms(int n) const {
	double sumOfNTerms = firstTerm_ * (pow(commonRatio_, n) - 1) / (commonRatio_ - 1);

	return sumOfNTerms;
}

GeometricSequence::GeometricSequence(double firstTerm, double commonRatio) : firstTerm_{ firstTerm }, TSeries() {
	assert(commonRatio != 0.0);
	commonRatio = commonRatio;
}

GeometricSequence::GeometricSequence() : firstTerm_{ 0.0 }, commonRatio_{ 0.0 }, TSeries() {}

void GeometricSequence::setFirstTerm(double firstTerm) { firstTerm_ = firstTerm; }

double GeometricSequence::getFirstTerm() const { return firstTerm_; }

void GeometricSequence::setCommonRatio(double commonRatio) {
	assert(commonRatio != 0.0);
	commonRatio = commonRatio;
}

double GeometricSequence::getCommonRatio() const { return commonRatio_; }

