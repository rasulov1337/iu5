#include "subscriber.h"

Subscriber::Subscriber() {
	name = new char[MAX_NAME_LENGTH];
	balance = 0;
	isMale = false;
	phoneNumber = 0;

	id = Subscriber::globalID++;
	cout << "Создание ID " << id << endl;
}

Subscriber::Subscriber(const Subscriber& s) {
	strcpy(name, s.getName());
	balance = s.balance;
	isMale = s.isMale;
	phoneNumber = s.phoneNumber;
	id = Subscriber::globalID++;
	cout << "Создание ID " << id << endl;
}

Subscriber::~Subscriber() {
	delete[] name;
	cout << "Удаление ID " << id << endl;
}

Subscriber& Subscriber::operator=(const Subscriber& s)
{
	strcpy(name, s.getName());
	balance = s.balance;
	isMale = s.isMale;
	phoneNumber = s.phoneNumber;
	return *this;
}


void Subscriber::edit() {
	cout << "Введите имя абонента\n";
	cin >> name;
	cout << "Введите его номер телефона\n";
	cin >> phoneNumber;
	cout << "Введите его баланс\n";
	cin >> balance;
	cout << "Введите его пол (0 -- Ж, 1 -- М)\n";
	cin >> isMale;
}

void Subscriber::setName(char* newName) {
	strcpy(name, newName);
}

char* Subscriber::getName() const {
	return name;
}

ifstream& operator>>(ifstream& in, Subscriber& s) {
	in >> s.name >> s.isMale >> s.phoneNumber >> s.balance;
	return in;
}

ofstream& operator<<(ofstream& out, const Subscriber& s) {
	out << s.name << ' ' << s.isMale << ' ' << s.phoneNumber << ' ' << s.balance << endl;
	return out;
}

bool Subscriber::operator<(const Subscriber& s) {
	if (phoneNumber < s.phoneNumber)
		return true;
	return false;
}


bool Subscriber::operator==(const Subscriber& s) {
	return phoneNumber == s.phoneNumber;
}