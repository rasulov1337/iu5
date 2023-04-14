#pragma once
#include <iostream>
#include <cstring>

using std::cout;

class Ship {
public:
	explicit Ship(const char* _country, const char* _name, int weight, bool add_to_list);
	explicit Ship(const Ship& s);
	~Ship();

	Ship& operator=(const Ship& s);

	virtual void print_data() const = 0;
	void add();
	int number_of_people;

	static Ship** array;
	static int array_size;
	static int max_array_size;
	static void print();
protected:
	char* name;
	char* country;
	int weight;
};