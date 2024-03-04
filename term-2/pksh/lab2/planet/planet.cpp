#include "planet.h"

int Planet::globalID = 0;


Planet::Planet() {
	name = new char[MAX_PLANET_NAME_LENGTH];
	diameter = 0;
	life = false;
	numberOfSatelites = 0;
	id = Planet::globalID++;
	cout << "Создание ID " << id << endl;
}

Planet::Planet(const Planet& p) {
	strcpy(name, p.getName());
	diameter = p.diameter;
	life = p.life;
	numberOfSatelites = p.numberOfSatelites;
	id = Planet::globalID++;
	cout << "Создание ID " << id << endl;
}


Planet::~Planet() {
	delete[] name;
	cout << "Удаление ID " << id << endl;
}

Planet& Planet::operator=(const Planet& p)
{
	strcpy(name, p.getName());
	diameter = p.diameter;
	life = p.life;
	numberOfSatelites = p.numberOfSatelites;
	return *this;
}


void Planet::edit() {
	cout << "Введите название планеты\n";
	cin >> name;
	cout << "Введите диаметр планеты\n";
	cin >> diameter;
	cout << "Введите, есть ли на ней жизнь\n";
	cin >> life;
	cout << "Введите количество спутников\n";
	cin >> numberOfSatelites;
}

void Planet::edit(char* newName, int diameter, bool life, int numberOfSatelites) {
	strcpy(name, newName);
	this->diameter = diameter;
	this->life = life;
	this->numberOfSatelites = numberOfSatelites;
}

void Planet::setName(char* newName) {
	strcpy(name, newName);
}

char* Planet::getName() const {
	return name;
}

ifstream& operator>>(ifstream& in, Planet& p) {
	in >> p.name >> p.diameter >> p.life >> p.numberOfSatelites;
	return in;
}

ofstream& operator<<(ofstream& out, const Planet& p) {
	out << p.name << ' ' << p.diameter << ' ' << p.life << ' ' << p.numberOfSatelites << endl;
	return out;
}



bool Planet::operator<( const  Planet& p) {
	if (diameter < p.diameter)
		return true;
	return false;
}


bool Planet::operator==( const  Planet& p) {
	return diameter == p.diameter;
}