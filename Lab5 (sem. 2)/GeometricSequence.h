#pragma once

#include "TSeries.h"

class GeometricSequence : public TSeries {
private:
	double commonRatio_;

public:
	virtual double getNthTerm(int n) const;
	virtual double getSumOfNTerms(int n) const;
	GeometricSequence(double firstTerm, double commonRatio);
	GeometricSequence();
	void setFirstTerm(double firstTerm);
	void setCommonRatio(double commonRatio);
	double getFirstTerm() const;
	double getCommonRatio() const;
};