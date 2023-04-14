#include "Task5.h"

Date::Date() : dd(1), mm(1), yy(1970) { }

Date::Date(int dd, int mm, int yy) : dd(dd), mm(mm), yy(yy) {}

void Date::print() const {
	cout << setfill('0') << setw(2) << dd << '.' << setw(2) << mm << '.' << yy << '\n';
}

bool Date::operator <(const Date& d) {
	bool y_check = (yy < d.yy);
	bool m_check = (yy == d.yy && mm < d.mm);
	bool d_check = (yy == d.yy && mm == d.mm && dd < d.dd);
	return (y_check || m_check || d_check);
}

bool Date::operator==(const Date& other) {
	return (dd == other.dd) && (mm == other.mm) && (yy == other.yy);
}

void printVector(const vector<Date>& v) {
	for (const auto& i : v)
		i.print();
}

void task5() {
	vector<Date> arr{
		Date(1, 2, 1963),
		Date(14, 7, 1995),
		Date(7, 12, 2088),
		Date(5, 3, 2030),
		Date(24, 9, 2013),
		Date(19, 9, 2020) };

	printVector(arr);
	cout << "\n\n";

	vector<Date> newArr;
	Date today(18, 03, 2023);
	for (int i = 0; i < arr.size(); ++i)
		if (today < arr[i])
			newArr.push_back(arr[i]);
	printVector(newArr);
}