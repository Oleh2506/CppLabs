#pragma once

#include "TSeries.h"

class GeometricSequence : public TSeries {
private:
	double firstTerm_, commonRatio_;

protected:
	virtual double calculateNthTerm(int n) const;
	virtual double calculateSumOfNTerms(int n) const;

public:
	GeometricSequence(double firstTerm, double commonRatio);
	GeometricSequence();
	void setFirstTerm(double firstTerm);
	void setCommonRatio(double commonRatio);
	double getFirstTerm() const;
	double getCommonRatio() const;
};