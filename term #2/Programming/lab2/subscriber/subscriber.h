#pragma once
#include <fstream>
#include <iostream>
#include <cstring>

#define MAX_NAME_LENGTH 30

using namespace std;

// абонент телефонной станции
class Subscriber {
public:
	Subscriber();
	Subscriber(const Subscriber&);
	~Subscriber();
	Subscriber& operator=(const Subscriber&);

	void edit();
	void setName(char* newName);
	char* getName() const;


	friend ifstream& operator>>(ifstream&, Subscriber&);
	friend ofstream& operator<<(ofstream&, const Subscriber&);

	bool operator<(const Subscriber& b);
	bool operator==(const Subscriber& b);
	static int globalID;

	unsigned long long phoneNumber;
	double balance;
	bool isMale;
private:
	int id;
	char* name;

};

