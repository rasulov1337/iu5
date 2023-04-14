#include "interactive.h"

int Subscriber::globalID = 0;


int read_db(char* filename, Subscriber* arr)
{
	ifstream fin(filename, ios::in);
	if (!fin)
	{
		cout << "Heт файла " << filename << endl;
		return 0;
	}
	int n;
	fin >> n;
	if (n > MAX_SUBS_NUM)
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

int write_db(char* filename, const Subscriber* arr, const int& n)
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

int menu() {
	cout << " ============== ГЛАВНОЕ МЕНЮ ========================\n";
	cout << "1 - прочитать БД из файла\t 5 - вывод базы на экран\n";
	cout << "2 - записать БД в файл\t\t 6 - отсортировать БД\n";
	cout << "3 - добавить нового абонента\t 7 - удалить абонента\n";
	cout << "4 - корректировка сведений\t 8 - выйти" << endl;
	cout << "Для выбора операции введите цифру от 1 до 7" << endl;
	int resp;
	cin >> resp;
	cin.clear();
	cin.ignore(10, '\n');
	return resp;
}

void print_db(Subscriber* arr, int n) {
	cout << " База Данных " << endl;
	cout << "  #  Имя                      Пол     Номер телефона    Баланс\n";
	for (int i = 0; i < n; ++i) {
		char sex = arr[i].isMale ? 'м' : 'ж';
		cout << setw(3) << i + 1 << ". " << arr[i].getName() << setw(20 - strlen(arr[i].getName()) + 6) <<
			sex << "       " << setw(11) << left << arr[i].phoneNumber <<
			"       " << arr[i].balance << endl;
	}
}

int find(Subscriber* arr, int n) {
	cout << "Введите имя абонента, которого вы хотите отредактировать\n";
	char* buff = new char[MAX_NAME_LENGTH];
	cin >> buff;

	int res = -1;
	for (int i = 0; i < n; ++i) {
		if (strcmp(arr[i].getName(), buff) == 0) {
			res = i;
		}
	}
	return res;
}

void sort_db(Subscriber* arr, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j)
				continue;
			if (arr[i] < arr[j]) {
				char buff[MAX_NAME_LENGTH];
				strcpy(buff, arr[i].getName());
				arr[i].setName(arr[j].getName());
				arr[j].setName(buff);
				swap(arr[i].phoneNumber, arr[j].phoneNumber);
				swap(arr[i].balance, arr[j].balance);
				swap(arr[i].isMale, arr[j].isMale);
			}
		}
	}
}

void add(Subscriber* arr, int& n) {
	arr[n].edit();
	++n;
}

void del(Subscriber* arr, int& n) {
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