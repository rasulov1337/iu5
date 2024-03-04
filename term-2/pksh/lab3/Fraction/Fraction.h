#pragma once
#include <numeric>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

#define N_DEC 4
#define N_DEC_DENOM pow(10, N_DEC)


class Fraction {
public:
    explicit Fraction(const char*);
    explicit Fraction(double a);
    explicit Fraction(int a=1, int b=1);

    Fraction& operator=(const Fraction&);
    Fraction& operator=(double);
    Fraction& operator=(const char*);
    
    int numerator;
    int denominator;

    // +
    Fraction operator+(const Fraction&) const;
    Fraction operator+(int) const;
    Fraction operator+(double) const;
    friend Fraction operator+(int, const Fraction&);
    friend Fraction operator+(double, const Fraction&);

    // +=
    Fraction& operator+=(const Fraction&);
    Fraction& operator+=(int a);
    Fraction& operator+=(double a);
    friend double& operator+=(double&, const Fraction&);

    friend ostream& operator<<(ostream&, const Fraction&);
    friend istream& operator>>(istream&, Fraction&);

    double toDouble() const;
private:
    void shorten();
    void parseStr(const char*);
};

Fraction toFraction(double a);