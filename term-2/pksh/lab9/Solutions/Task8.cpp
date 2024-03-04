#include "Task8.h"

void task8() {
	Inventory inventory = { {"Отверка", 0},
		{"Молоток", 10},
		{"Гайки", 100},
		{"Профиль", 0},
		{"Уголок", 9},
		{"Доска", 17} };

	for (const auto& i : inventory) {
		if (i.second != 0) {
			cout << i.first << " - " << i.second << '\n';
		}
	}
}