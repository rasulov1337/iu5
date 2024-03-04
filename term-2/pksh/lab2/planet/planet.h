#pragma once
#include <fstream>
#include <iostream>
#include <cstring>

#define MAX_PLANET_NAME_LENGTH 30

using namespace std;


class Planet {
public:
	Planet();
	Planet(const Planet&);
	~Planet();
	Planet& operator=(const Planet&);

	void edit();
	void edit(char* newName, int diameter, bool life, int numberOfSatelites);
	void setName(char* newName);
	char* getName() const;
	int diameter;
	bool life;
	int numberOfSatelites;


	friend ifstream& operator>>(ifstream&, Planet&);
	friend ofstream& operator<<(ofstream&, const Planet&);

	bool operator<(const Planet& b);
	bool operator==(const Planet& b);
	static int globalID;
private:
	int id;
	char* name;

};


