#include "Task6.h"

using namespace std;


void task6() {
	cout << "Написать программe для ввода с клавиатуры массива строк (окончание ввода строк – пустая строка), которые записать в вектор. Распечатать введенный массив строк в столбик с указанием номера каждой строки. Удалить из вектора элемент с индексом 3 и снова распечатать вектор. Переделать программу: печатать вектор с помощью функции.\n";
	vector<string> vec;

	string line;
	getline(cin, line);
	while (!line.empty()) {
		vec.push_back(line);
		getline(cin, line);
	}

	cout << "Original vector:\n";
	printVec6(vec);

	cout << "Deleting element with index 3...\n";
	vec.erase(vec.begin() + 3);

	cout << "Modified vector:\n";
	printVec6(vec);
}

void printVec6(const vector<string>& vec) {
	for (int i = 0; i < vec.size(); ++i)
		cout << "#" << i + 1 << ". " << vec[i] << '\n';
}