#pragma once

class TSeries {
protected:
	double firstTerm_;

public:
	TSeries(double firstTerm);
	virtual double getNthTerm(int n) const = 0;
	virtual double getSumOfNTerms(int n) const = 0;
};