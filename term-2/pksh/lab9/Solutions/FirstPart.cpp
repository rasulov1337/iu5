#include "FirstPart.h"

/* Пользователь вводит 3 слова - Имя, Отчество, Фамилия в 3-х разных переменных.
Образовать новую символьную переменную, хранящую только ваши инициалы (через точку и пробел).*/
void task1() {
	string firstName, middleName, lastName;
	cout << "Введите ваше имя, отчество и фамилию, все через пробел" << endl;
	cin >> firstName >> middleName >> lastName;

	string initials = firstName.substr(0, 1) + ". " + middleName.substr(0, 1) + ". " + lastName.substr(0, 1) + ".";
	cout << "Ваши инициалы: " << initials << endl;
	cin.ignore();
}

/* Пользователь вводит некоторый текст из символов латинского алфавита, содержащий букву «а».
Напечатать все символы, расположенные за первой буквой «а» до ее второго вхождения
или до конца текста. */
void task2() {
	cout << "Task #2. Пользователь вводит некоторый текст из символов латинского алфавита, содержащий букву «а».\
		Напечатать все символы, расположенные за первой буквой «а» до ее второго вхождения\
		или до конца текста.\n";
	string text;
	getline(cin, text);
	int a = text.find('a');
	int b = text.substr(a + 1).find('a');
	if (b != string::npos) {
		b += a + 1;
		cout << text.substr(a, b - a + 1);
	}
	else
		cout << text.substr(a);

}


string processString(string a) {
	string res;
	for (int i = 0; i < a.size(); ++i)
		if (a[i] == '.')
			res += "...";
		else
			res += a[i];
	return res;
}


void task3() {
	ifstream in("text.txt");
	if (!in) {
		cerr << "Couldn't open the file (task 3)! Error!\n";
		exit(EXIT_FAILURE);
	}

	cout << "Original text:\n";
	cout << in.rdbuf() << endl;

	in.seekg(0);
	string line;
	ofstream out("new-text.txt");
	cout << "New text:\n";
	while (getline(in, line)) {
		string processedLine = processString(line);
		out << processedLine;
		cout << processedLine;
	}
}

void printVec(const vector<string>& vec) {
	for (int i = 0; i < vec.size(); ++i)
		cout << "#" << i + 1 << ". " << vec[i] << '\n';
}

void task4() {
	cout << "Написать программe для ввода с клавиатуры массива строк (окончание ввода строк – пустая строка), которые записать в вектор. Распечатать введенный массив строк в столбик с указанием номера каждой строки. Удалить из вектора элемент с индексом 3 и снова распечатать вектор. Переделать программу: печатать вектор с помощью функции.\n";
	vector<string> vec;

	string line;
	getline(cin, line);
	while (!line.empty()) {
		vec.push_back(line);
		getline(cin, line);
	}

	cout << "Original vector:\n";
	printVec(vec);

	cout << "Deleting element with index 3...\n";
	vec.erase(vec.begin() + 3);

	cout << "Modified vector:\n";
	printVec(vec);
}