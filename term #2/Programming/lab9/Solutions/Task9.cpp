#include "Task9.h"

void print_pupils(const map<string, int>& p) {
	cout << "CLASS NUMBER OF PUPILS\n";
	for (const auto& i : p) {
		cout << i.first << " - " << i.second << '\n';
	}
}

void task9() {
	map<string, int> pupils = { {"1а", 21},
		{"1б", 20},
		{"2", 25},
		{"3а", 20},
		{"3б", 23},
		{"4а", 25},
		{"4б", 25},
		{"5а", 26},
		{"5б", 25},
		{"6a", 19},
		{"6б", 18},
		{"7а", 26},
		{"7б", 25},
		{"8", 25},
		{"9", 17},
		{"10", 15},
		{"11", 14}
	};

	int sum = std::accumulate(
		pupils.begin(),
		pupils.end(),
		0,
		[](int val, const map<string, int>::value_type& p) {
			return val + p.second;
		});
	cout << "Overall number of pupils: " << sum << '\n';

	print_pupils(pupils);
}