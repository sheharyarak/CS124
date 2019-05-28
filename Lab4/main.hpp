#include <iostream>
#include <string>

using namespace std;

class Term
{
public:
	Term *nxt = nullptr;
	int coeff;
	int exp;
	Term(int exp, int coeff);
};

class Polynomial
{
public:
	Term *h = nullptr;
	Term *t = nullptr;
	void addTerm(int coeff, int exp);
	void addToStart(Term *newterm);
	void addToEnd(Term *newterm);
	void addInPlace(Term *newterm);
	Polynomial operator+ (Polynomial right);
	Polynomial operator* (Polynomial right);
};
