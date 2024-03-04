#include "Term.h"


Term::Term(): k(0), power(0) {}
Term::Term(int k) : k(k), power(0) {}
Term::Term(int k, int p) : k(k), power(p) {}

Term Term::operator+(const Term& t) {
	return Term(t.k + k, power);
}


istream& operator>>(istream& in, Term& t) {
	char buff[512];
	cin.getline(buff, 512);

	int sign = 1;
	int currNum = 0;
	if (buff[0] == 'x' || (buff[0] == '-' && buff[1] == 'x'))
		currNum = 1;
	for (int i = 0; i < 512; ++i) {
		if (buff[i] == ' ')
			continue;
		else if (buff[i] == '-')
			sign = -sign;
		if (buff[i] == 'x') {
			t.k = currNum * sign;
			currNum = 0;
			sign = 1;
		}
		else if (buff[i] == '\0') {
			t.power = currNum * sign;
		}
		else if (buff[i] >= '0' && buff[i] <= '9')
			currNum = currNum * 10 + (buff[i] - '0');

	}
	return in;
}


ostream& operator<<(ostream& out, const Term& t) {
	if (t.k < 0)
		out << '-';
	
	int k = abs(t.k);

	if (k == 0) {
		out << 0 << endl;
		return out;
	}

	if (!(k == 1 && t.power != 0)) // Когда не выполняется случаи, когда не надо выводить коэф
		out << k;
	if (t.power != 0) {
		out << 'x';
		if (t.power != 1)
			out << '^' << t.power;
	}
	return out;
}

