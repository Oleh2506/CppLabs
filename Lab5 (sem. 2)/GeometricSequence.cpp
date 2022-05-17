#include "GeometricSequence.h"
#include <cassert>
#include <cmath>

double GeometricSequence::getNthTerm(int n) const {
	assert(n > 0);

	double nthTerm = firstTerm_ * pow(commonRatio_, n - 1);

	return nthTerm;
}


double GeometricSequence::getSumOfNTerms(int n) const {
	assert(n > 0);
	double sumOfNTerms{};

	if (commonRatio_ != 1.0) {
		sumOfNTerms = firstTerm_ * (pow(commonRatio_, n) - 1) / (commonRatio_ - 1);
	}
	else {
		sumOfNTerms = firstTerm_ * n;
	}
	return sumOfNTerms;
}

GeometricSequence::GeometricSequence(double firstTerm, double commonRatio) : commonRatio_{ commonRatio }, TSeries( firstTerm ) {
	assert(commonRatio != 0.0);
}

GeometricSequence::GeometricSequence() : commonRatio_{ 1.0 }, TSeries( 0.0 ) {}

void GeometricSequence::setFirstTerm(double firstTerm) { firstTerm_ = firstTerm; }

double GeometricSequence::getFirstTerm() const { return firstTerm_; }

void GeometricSequence::setCommonRatio(double commonRatio) {
	assert(commonRatio != 0.0);
	commonRatio_ = commonRatio;
}

double GeometricSequence::getCommonRatio() const { return commonRatio_; }

