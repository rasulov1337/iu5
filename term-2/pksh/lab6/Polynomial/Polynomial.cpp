#include "Polynomial.h"


Polynomial::Polynomial() {
	degree = size = order_ = 0;
	poly = new Term[POLY_DEFAULT_SIZE];
	maxSize = POLY_DEFAULT_SIZE;
}

Polynomial::Polynomial(int k) {
	degree = 0;
	size = 1;
	maxSize = POLY_DEFAULT_SIZE;
	order_ = false;
	poly = new Term[POLY_DEFAULT_SIZE];
	poly[0] = Term(k);
}

Polynomial::Polynomial(const Term& t) {
	degree = t.power;
	size = 1;
	maxSize = POLY_DEFAULT_SIZE;
	order_ = false;
	poly = new Term[POLY_DEFAULT_SIZE];
	poly[0] = t;
}

Polynomial::Polynomial(const Polynomial& p) {
	degree = p.degree;
	size = p.size;
	maxSize = POLY_DEFAULT_SIZE;
	order_ = p.order_;
	poly = new Term[size];
	for (int i = 0; i < size; ++i) {
		poly[i] = p.poly[i];
	}
}

Polynomial& Polynomial::operator=(const Polynomial& p) {
	if (&p == this)
		return *this;

	degree = p.degree;
	size = p.size;
	order_ = p.order_;
	poly = new Term[size];
	maxSize = p.maxSize;
	for (int i = 0; i < size; ++i) {
		poly[i] = p.poly[i];
	}
	return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial& p) {
	for (int i = 0; i < p.getSize(); ++i) {
		Term t = p[i];
		if (t.k == 0)
			continue;
		int index;
		if (contains(t.power, &index)) {
			poly[index].k += t.k;
			if (poly[index].k == 0) {
				for (int k = index; k < size; ++k)
					poly[k] = poly[k + 1];
				--size;
			}
		}
		else {
			poly[size++] = t;
			resize();
		}
	}
	sort();
	return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& p)
{
	Polynomial newP = (*this) * p;
	
	*this = newP;
	sort();
	return *this;
}

Term Polynomial::operator[](int index) const {
	return poly[index];
}

bool Polynomial::contains(int power, int* index) const
{
	// Binary search
	int l = 0, r = size - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		int midPower = poly[mid].power;
		if (midPower == power) {
			if (index != nullptr)
				*index = mid;
			return true;
		}
		else if ((!order_ && midPower < power) || (order_ && midPower > power))
			r = mid - 1;
		else
			l = mid + 1;
	}
	if (index != nullptr)
		*index = -1;
	return false;
}

void Polynomial::setOrder(bool reverse) {
	order_ = reverse;
	sort();
}

void Polynomial::sort()
{
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (i == j)
				continue;
			bool condition = poly[i].power > poly[j].power;
			if (order_)
				condition = !condition;
			if (condition) {
				swap(poly[i], poly[j]);
			}
		}
	}
	degree = poly[0].power;
}

void Polynomial::resize() {
	int newMaxSize;
	if (maxSize == size)
		newMaxSize = size * 1.5;
	else if (size < maxSize / 2)
		newMaxSize = MAX((int)(size / 1.5), POLY_DEFAULT_SIZE);
	else
		return;
	Term* newPointer = new Term [newMaxSize];
	if (poly) {
		for (int i = 0; i < size; ++i)
			newPointer[i] = poly[i];
		delete[] poly;
	}

	poly = newPointer;
	maxSize = newMaxSize;
}

Polynomial operator*(const Polynomial& a, const Polynomial& b) {
	Polynomial res;
	for (int i = 0; i < a.size; ++i) {
		for (int j = 0; j < b.size; ++j) {
			res += Term(a[i].k * b[j].k, a[i].power + b[j].power);
		}
	}
	return Polynomial(res);
}

Polynomial operator+(const Polynomial& a, const Polynomial& b) {
	Polynomial res;
	for (int i = 0; i < a.size; ++i)
		res += a[i];
	for (int j = 0; j < b.size; ++j)
		res += b[j];
	return Polynomial(res);
}

ostream& operator<<(ostream& out, const Polynomial& p) {
	if (p.size > 0) {
		out << p.poly[0];
		for (int i = 1; i < p.size; ++i) {
			if (p.poly[i].k > 0)
				out << " + ";
			else
				out << " - ";

			out << Term(abs(p.poly[i].k), p.poly[i].power);
		}
	}
	return out;
}