#include "funcs.h"

int read_db(char* filename, Planet* arr)
{
	ifstream fin(filename, ios::in);
	if (!fin)
	{
		cout << "Heт файла " << filename << endl;
		return 0;
	}
	int n;
	fin >> n;
	if (n > MAX_PLANET_SIZE)
	{
		cout << "Переполнение БД. n= " << n << endl;
		return 1;
	}

	for (int i = 0; i < n; i++) {
		if (fin.peek() == EOF) {
			break;
		}
		fin >> arr[i];
	}
	fin.close();
	return n;
}

int write_db(char* filename, const Planet* arr, const int& n)
{
	ofstream fout(filename, ios::out);
	if (!fout)
	{
		cout << "Ошибка открытия файла" << endl;
		return 1;
	}
	fout << n << endl;
	for (int i = 0; i < n; i++)
		fout << arr[i];
	fout.close();
	return 0;
}

void print_db(Planet* arr, int n) {
	cout << " База Данных " << endl;
	cout << "  #  Название           Диаметр        Жизнь       Спутники\n";
	for (int i = 0; i < n; ++i) {
		cout << setw(3) << i + 1 << ". " << arr[i].getName() << setw(20 - strlen(arr[i].getName()) + 6) <<
			arr[i].diameter << "            " << arr[i].life <<
			"              " << arr[i].numberOfSatelites << endl;
	}
}

int find(Planet* arr, int n) {
	cout << "Введите название планеты, которую хотите отредактировать\n";
	char* buff = new char[MAX_PLANET_NAME_LENGTH];
	cin >> buff;

	int res = -1;
	for (int i = 0; i < n; ++i) {
		if (strcmp(arr[i].getName(), buff) == 0) {
			res = i;
		}
	}
	return res;
}

int find(Planet* arr, int n, char* name) {
	int res = -1;
	for (int i = 0; i < n; ++i) {
		if (strcmp(arr[i].getName(), name) == 0) {
			res = i;
		}
	}
	return res;
}

void sort_db(Planet* arr, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j)
				continue;
			if (arr[i] < arr[j]) {
				char buff[MAX_PLANET_NAME_LENGTH];
				strcpy(buff, arr[i].getName());
				arr[i].setName(arr[j].getName());
				arr[j].setName(buff);
				swap(arr[i].diameter, arr[j].diameter);
				swap(arr[i].life, arr[j].life);
				swap(arr[i].numberOfSatelites, arr[j].numberOfSatelites);
			}
		}
	}
}

void add(Planet* arr, int& n) {
	arr[n].edit();
	++n;
}

void add(Planet* arr, int& n, char* newName, int diameter, bool life, int numberOfSatelites) {
	arr[n].edit(newName, diameter, life, numberOfSatelites);
	++n;
}

void del(Planet* arr, int& n) {
	print_db(arr, n);
	cout << "Введите номер элемента, который хотите удалить\n";
	int a;
	cin >> a;
	--a;
	if (a < 0 || a > n) {
		cout << "Ошибка! Такого индекса нет\n";
		return;
	}

	for (int i = a; i < n; ++i) {
		arr[i] = arr[i + 1];
	}
	--n;
}

void del(Planet* arr, int& n, char* name) {
	int res = -1;
	for (int i = 0; i < n; ++i) {
		if (strcmp(arr[i].getName(), name) == 0) {
			res = i;
		}
	}
	if (res == -1) {
		cout << "Такой планеты нет!\n";
		return;
	}

	for (int i = res; i < n; ++i) {
		arr[i] = arr[i + 1];
	}
	--n;
}