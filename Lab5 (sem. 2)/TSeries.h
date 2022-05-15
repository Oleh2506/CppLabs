#pragma once

class TSeries {
protected:
	virtual double calculateNthTerm(int n) const = 0;
	virtual double calculateSumOfNTerms(int n) const = 0;

public:
	double getNthTerm(int n) const;
	double getSumOfNTerms(int n) const;
};