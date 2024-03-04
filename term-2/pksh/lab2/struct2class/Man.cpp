#include "Man.h"

Man::Man() { 
	name = new char[NAME_LENGTH];
	for (int i = 0; i < NAME_LENGTH; ++i)
		name[i] = '\0';
	birth_year = 0;
	pay = 0;
}

Man::Man(const Man& adam) {
	strcpy(name, adam.getName());
	birth_year = adam.birth_year;
	pay = adam.pay;
}

Man& operator=(const Man& adam) {
	strcpy(name, adam.getName());
	birth_year = adam.birth_year;
	pay = adam.pay;
	return *this;
}

Man::~Man() { 
	delete[] name; 
}

// Возвращаем копию, чтобы исходный объект не могли модифицировать
char* Man::getName() {
	return name;
}

int Man::getBirthYear() {
	return birth_year;
}

float Man::getPay() {
	return pay;
}

void Man::setName(char* name) {
	strcpy(this->name, name);
}

void Man::setBirthYear(int year) {
	birth_year = year;
}

void Man::setPay(float pay) {
	this->pay = pay;
}