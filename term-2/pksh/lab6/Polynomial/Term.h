#pragma once
#include <iostream>
#include <string>

using namespace std;


class Term {
	friend class Polynomial;
public:
	explicit Term();
	explicit Term(int);
	explicit Term(int, int);
	int k;
	int power;
	Term operator+(const Term&);

	friend istream& operator>>(istream&, Term&);
	friend ostream& operator<<(ostream&, const Term&);
};