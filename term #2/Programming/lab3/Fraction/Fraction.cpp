#include "Fraction.h"


Fraction::Fraction(const char* str) {
    parseStr(str);
    shorten();
}

Fraction::Fraction(double a) {
    numerator = a * N_DEC_DENOM;
    denominator = N_DEC_DENOM;
    shorten();
}

Fraction::Fraction(int a, int b) {
    numerator = a;
    denominator = b;
    shorten();
}

Fraction& Fraction::operator=(const Fraction& a) {
    numerator = a.numerator;
    denominator = a.denominator;
    return *this;
}

Fraction& Fraction::operator=(const char* str) {
    parseStr(str);
    return *this;
}

Fraction& Fraction::operator=(double a) {
    numerator = a;
    denominator = 1;
    return *this;
}

Fraction Fraction::operator+(const Fraction& a) const {
    int d = lcm(a.denominator, denominator);
    int n = d / a.denominator * a.numerator + d / denominator * numerator;

    Fraction f(n, d);
    f.shorten();
    return f;
}

Fraction Fraction::operator+(int a) const {
    int d = denominator;
    int n = a * d + numerator;

    Fraction f(n, d);
    f.shorten();
    return f;
}

Fraction Fraction::operator+(double a) const {
    return toFraction(a) + *this;
}

void Fraction::parseStr(const char* str) {
    int sign = str[0] == '-' ? -1 : 1;
    bool wasInitialized[] = {false, false, false};
    int nums[3] = {0, 0, 0};

    int currNum = 0;

    int strLen = strlen(str);

    for (int i = 0; i <= strLen; ++i) {
        if (str[i] == '-')
            continue;
        else if (str[i] == ' ') {
            nums[0] = currNum;
            wasInitialized[0] = true;
            currNum = 0;
            continue;
        }
        else if (str[i] == '/') {
            nums[1] = currNum;
            wasInitialized[1] = true;
            wasInitialized[0] = true;
            currNum = 0;
            continue;
        }
        else if (str[i] == '\0') {
            if (!wasInitialized[0]) {
                numerator = currNum;
                denominator = 1;
                return;
            }
            else if (!wasInitialized[2]) {
                nums[2] = currNum;
                wasInitialized[2] = true;
            }
        }
        currNum = currNum * 10 + (str[i] - '0');
    }

    denominator = nums[2];
    numerator = (nums[0] * denominator + nums[1]) * sign;

    if (denominator == 0) {
        cerr << "Ошибка! Знаменатель = 0\n";
        exit(0);
    }
}

Fraction& Fraction::operator+=(const Fraction& a) {
    int d = lcm(a.denominator, denominator);
    int n = d / a.denominator * a.numerator + d / denominator * numerator;

    denominator = d;
    numerator = n;

    shorten();
    return *this;
}

Fraction& Fraction::operator+=(int a) {
    int d = denominator;
    int n = a * d + numerator;

    numerator = n;
    denominator = d;
    shorten();
    return *this;
}

Fraction& Fraction::operator+=(double a) {
    Fraction f = toFraction(a);
    return *this+=(f);
}

double& operator+=(double& a, const Fraction& b) {
    a += b.toDouble();
    return a;
}

void Fraction::shorten() {
    int a = gcd(numerator, denominator);
    if (a == 1) 
        return;
    numerator /= a;
    denominator /= a;
}

double Fraction::toDouble() const {
    return (numerator * 1.0 / denominator);
}

ostream& operator<<(ostream& out, const Fraction& s) {
    if (s.numerator == 0) {
        out << 0;
        return out;
    }
    int wholePart = s.numerator / s.denominator;
    int n = abs(s.numerator - wholePart * s.denominator);
    int d = s.denominator;

    if (s.numerator < 0)
        out << '-';
    if (wholePart)
        out << abs(wholePart) << ' ';
    if (n != 0) 
        out << n << '/' << d;
    return out;
}

istream& operator>>(istream& in, Fraction& f) {
    char buff[512];
    in.getline(buff, 512);
    f.parseStr(buff);
    return in;
}

Fraction operator+(int num, const Fraction& a) {
    return a + num;
}

Fraction operator+(double num, const Fraction& a) {
    return a + num;
}


Fraction toFraction(double a) {
    return Fraction(a * N_DEC_DENOM, N_DEC_DENOM);
}