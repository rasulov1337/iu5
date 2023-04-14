#pragma once
#include <iostream>
#include <cstring>

using namespace std;

#define NAME_LENGTH 20

class Man {
public:
	Man();
	Man(const Man& adam);
	~Man();

	Man& operator=(const Man& adam);

	char* getName();
	int getBirthYear();
	float getPay();
	void setName(char* name);
	void setBirthYear(int year);
	void setPay(float pay);

private:
	char* name;
	int birth_year;
	float pay;
};