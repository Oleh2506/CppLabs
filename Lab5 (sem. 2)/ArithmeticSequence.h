#pragma once

#include "TSeries.h"

class ArithmeticSequence : public TSeries {
private:
	double commonDifference_;

public:
	virtual double getNthTerm(int n) const;
	virtual double getSumOfNTerms(int n) const;
	ArithmeticSequence(double firstTerm, double commonDifference);
	ArithmeticSequence();
	void setFirstTerm(double firstTerm);
	void setCommonDifference(double commonDifference);
	double getFirstTerm() const;
	double getCommonDifference() const;
};