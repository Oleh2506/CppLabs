#include "TSeries.h"
#include <cassert>

double TSeries::getNthTerm(int n) const {
	assert(n > 0);
	return calculateNthTerm(n);
}

double TSeries::getSumOfNTerms(int n) const {
	assert(n > 0);
	return calculateSumOfNTerms(n);
}