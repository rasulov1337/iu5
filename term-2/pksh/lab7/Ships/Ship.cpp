#include "Ship.h"
#include "Ship.h"

Ship::Ship(const char* _country, const char* _name, int weight, bool add_to_list)
		: weight(weight), number_of_people(0) {
	country = new char[strlen(_country) + 1];
	strcpy(country, _country);

	name = new char[strlen(_name) + 1];
	strcpy(name, _name);

	if (add_to_list)
		this->add();

}

Ship::Ship(const Ship& s) {
	weight = s.weight;
	number_of_people = s.number_of_people;

	country = new char[strlen(s.country) + 1];
	strcpy(country, s.country);

	name = new char[strlen(s.name) + 1];
	strcpy(name, s.name);
}

Ship& Ship::operator=(const Ship& s) {
	if (this != &s) {
		delete[] name;
		delete[] country;

		country = new char[strlen(s.country) + 1];
		strcpy(country, s.country);

		name = new char[strlen(s.name) + 1];
		strcpy(name, s.name);

		weight = s.weight;
		number_of_people = s.number_of_people;
	}
	return *this;
}

Ship::~Ship() {
	delete[] country;
	delete[] name;
}


void Ship::add()
{
	if (Ship::array_size + 1 > max_array_size) {
		Ship** new_array = new Ship*[(int) (max_array_size * 1.5)];
		for (int i = 0; i < array_size; ++i) {
			new_array[i] = Ship::array[i];
		}
		new_array[array_size++] = this;

		delete[] Ship::array;
		Ship::max_array_size *= 1.5;
		Ship::array_size++;
		Ship::array = new_array;
	}
	else
		Ship::array[Ship::array_size++] = this;
}

void Ship::print()
{
	for (int i = 0; i < Ship::array_size; ++i) {
		Ship::array[i]->print_data();
		cout << '\n';
	}
}
