#include "Task7.h"

Time::Time() : hh(0), mm(0), ss(0) {}

Time::Time(int hh, int mm, int ss) : hh(hh), mm(mm), ss(ss) {}

bool Time::operator < (const Time& t) const {
	bool h_check = (hh < t.hh);
	bool m_check = (hh == t.hh && mm < t.mm);
	bool s_check = (hh == t.hh && mm == t.mm && ss < t.ss);
	return (h_check || m_check || s_check);
}

bool Time::operator == (const Time& t) const {
	return (hh == t.hh) && (mm == t.mm) && (ss == t.ss);
}

void Time::print() const {
	cout << setfill('0') << setw(2) << hh << ':' << setw(2) << mm << ':' << setw(2) << ss << '\n';
}


void printTime(const list<Time>& q) {
	for (const auto& i : q)
		i.print();
}


void task7() {
	list<Time> list_uno = { Time(1, 2, 63), Time(14, 57, 19), Time(7, 32, 20), Time(5, 13, 23), Time(10, 19, 45), Time(19, 9, 59) };
	printTime(list_uno);

	list<Time> newList;
	Time a(0, 0, 0);
	Time b(5, 0, 0);
	for (auto i = list_uno.begin(); i != list_uno.end(); ++i) {
		if (*i < b && a < *i) {
			newList.push_back(*i);
		}
	}
	printTime(newList);
}