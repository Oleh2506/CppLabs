#pragma once

#include "TSeries.h"

class ArithmeticSequence : public TSeries {
private:
	double firstTerm_, commonDifference_;

protected:
	virtual double calculateNthTerm(int n) const;
	virtual double calculateSumOfNTerms(int n) const;

public:
	ArithmeticSequence(double firstTerm, double commonDifference);
	ArithmeticSequence();
	void setFirstTerm(double firstTerm);
	void setCommonDifference(double commonDifference);
	double getFirstTerm() const;
	double getCommonDifference() const;
};