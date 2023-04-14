#pragma once
#include "Term.h"

#define POLY_DEFAULT_SIZE 5
#define MAX(a, b)  (((a) > (b)) ? (a) : (b)) 


class Polynomial {
public:
	explicit Polynomial();
	explicit Polynomial(int);
	explicit Polynomial(const Term&);
	explicit Polynomial(const Polynomial&);

	Polynomial& operator=(const Polynomial&);
	Polynomial& operator+=(const Polynomial&);
	Polynomial& operator*=(const Polynomial&);
	Polynomial& operator=(const Term& t) { return this->operator=(Polynomial(t)); }
	Polynomial& operator+=(const Term& t) { return this->operator+=(Polynomial(t)); }
	Polynomial& operator*=(const Term& t) { return this->operator*=(Polynomial(t)); }
	Term operator[](int index) const;
	
	friend Polynomial operator*(const Polynomial&, const Polynomial&);
	friend Polynomial operator+(const Polynomial&, const Polynomial&);
	
	friend ostream& operator<<(ostream&, const Polynomial&);
	int getSize() const { return size; }

	// Returns whethere there is a term with that power or not
	bool contains(int, int* index=nullptr) const;

	void setOrder(bool reverse);

private:
	Term* poly;
	int size;
	int maxSize;
	int degree;
	bool order_;

	void sort();
	void resize();
};