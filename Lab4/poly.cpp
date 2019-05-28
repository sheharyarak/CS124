#include "main.hpp"

Term::Term(int coeff, int exp)
{
	this->exp = exp;
	this->coeff = coeff;
}

void Polynomial::addTerm(int coeff, int exp)
{
	Term *newterm = Term(coeff, exp);

	if (this->h == nullptr)
		addToStart(newterm);
	else if (exp >= this->t->exp)
	{
		if (exp > this->t->exp)
		{
			addToEnd(newterm);
		}
		else
		{
			this->t->coeff += coeff;
		}
	}
	else
	{
		addInPlace(newterm);
	}
}

void Polynomial::addToStart(Term *newterm)
{
	this->h = newterm;
	this->t = newterm;
}

void Polynomial::addToEnd(Term *newterm)
{
	this->t->next = newterm;
	this->t = newterm;
}

void Polynomial::addInPlace(Term * newterm)
{
	Term *trav = this->h;
	while (trav->nxt != nullptr && trav->next->exp <= newterm->exp)
	{
		trav = trav->nxt;
	}
	if (trav->nxt->exp == newterm->exp)
		trav->nxt->coeff += newterm->coeff;
	else
	{
		Term *tmp = trav->nxt;
		trav->nxt = newterm;
		newterm->nxt = tmp;
	}
}

Polynomial Polynomial::operator+(Polynomial right)
{
	Term *t1 = this->h;
	Term *t2 = right->h;
	while (t1->nxt != nullptr && t2->nxt != nullptr)
	{
		if (t1->exp == t2->exp)
			t1->coeff += t2->coeff;
		else if (t2->exp < t1->exp)
		{
			addInPlace(t2);
		}
		if (t1->nxt == nullptr && t2->nxt != nullptr)
			t2 = t2->nxt;
		else if (t1->nxt != nullptr && t2->nxt == nullptr)
			t1 = t1->nxt;
		else
		{
			t1 = t1->nxt;
			t2 = t2->nxt;
		}
	}
	return (this);
}

Polynomial Polynomial::operator*(Polynomial right)
{
	Term *t1 = this->h;
	Term *t2 = nullptr;
	Polynomial result;
	while (t1->nxt != nullptr)
	{
		t2 = right->h;
		while (t2->nxt != null)
		{
			result.addTerm(t1->coeff * t2->coeff, t1->exp + t2->exp);
			t2 = t2->nxt;
		}
		t1 = t1->nxt;
	}
	return (result);
}