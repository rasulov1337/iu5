#include <iostream>
#include <iomanip>
#include <fstream>
#include "Man.h"

using namespace std;

#define l_name  20


int read_dbase(char* filename, Man* arr, int& n);
int  menu();
int menu_f();
void print_dbase(Man* arr, int n);

int  write_dbase(char* filename, Man* arr, int n);

void add(Man* arr, int& n);
void remove(Man* arr, int& n);
void edit(Man* arr);
int find(Man* arr, int n, char* name);
int find(Man* arr, int n, int birth_year);
int find(Man* arr, int n, float pay);
void find_man(Man* arr, int n);

//----------------------------------------  Главная функция
int main()
{
	setlocale(0, "Russian");
	const int N = 100;
	Man arr[N];
	char filename[]  = "dbase.txt";
	int n = 0;
	//чтение БД в ОП
	if (read_dbase(filename, arr, n)) {
		cout << "Ошибка чтения БД" << endl;
		return 1;
	}
	print_dbase(arr, n);
	while (true) {
		switch (menu())
		{
		case 1: add(arr,n ); break; 
		case 2: remove(arr,n); break;
		case 3: find_man(arr, n);  break;
		case 4: edit(arr); break; 
		case 5: print_dbase(arr, n); break;
		case 6: write_dbase(filename, arr, n); break;
		case 7: return 0;
		default: cout << " Недопустимый номер операции" << endl; break;
		}
	}
	return 0;
}
////////////////////////////////////////////////////////
int menu()
{
	cout << " ============== ГЛАВНОЕ МЕНЮ ========================\n";
	cout << "l - добавление сотрудника\t 4 - корректировка сведений" << endl;
	cout << "2 - удаление coтpyдникa\t\t 5 - вывод базы на экран" << endl;
	cout << "3 - поиск сотрудника\t\t 6 - вывод базы в файл" << endl;
	cout << "\t\t\t\t 7 - выход" << endl;
	cout << "Для выбора операции введите цифру от 1 до 7" << endl;
	int resp;
	cin >> resp;
	cin.clear();
	cin.ignore(10, '\n');
	return resp;
}

// ------------------------------------	Чтение базы из файла
int read_dbase(char* filename, Man* arr, int& n)
{
	ifstream fin(filename, ios::in);
	if (!fin)
	{
		cout << "Heт файла " << filename << endl;
		return 1;
	}
	fin >> n;
	if (n > 100)
	{
		cout << "Переполнение БД. n= " << n << endl;
		return 1;
	}
	char* name = new char[l_name];
	int y;
	float f;
	for (int i = 0; i < n; i++) {
		fin >> name >> y >> f;
		if (fin.eof()) {
			break;
		}
		arr[i].setName(name);
		arr[i].setBirthYear(y);
		arr[i].setPay(f);
	}

	fin.close();
	return 0;
}
//------------------------------------	Вывод базы в файл
int write_dbase(char* filename, Man* arr, int n)
{
	ofstream fout(filename, ios::out);
	if (!fout)
	{
		cout << "Ошибка открытия файла" << endl;
		return 1;
	}
	fout << n << endl;
	for (int i = 0; i < n; i++)
		fout << arr[i].getName() << ' ' << arr[i].getBirthYear() << ' ' << arr[i].getPay() << endl;

	fout.close();
	return 0;
}
//------------------------------ Вывод базы на экран
void print_dbase(Man* arr, int n)
{
	cout << " База Данных " << endl;
	for (int i = 0; i < n; ++i) {
		char* currName = arr[i].getName();
		cout << setw(3) << i + 1 << ". " << currName << setw(20 - strlen(arr[i].getName()) + 6)
			 << arr[i].getBirthYear() << setw(10) << arr[i].getPay() << endl;
		delete[] currName;
	}
}

void add(Man* arr, int& n) 
{
	char* name = new char[l_name];
	int by;
	float pay;

	cout << "Введите, пожалуйста, имя человека\n";
	cin >> name;
	cout << "Введите, пожалуйста, год его рождения\n";
	cin >> by;
	cout << "А теперь введите его зарплату\n";
	cin >> pay;

	arr[n].setName(name);
	arr[n].setBirthYear(by);
	arr[n].setPay(pay);

	delete[] name;
	++n;
}

void edit(Man* arr) {
	print_dbase(arr, n);
	int k;
	cout << "Введите индекс сотрудника, который вы хотите изменить\n";
	cin >> k;
	--k;
	add(arr, k);
}

void remove(Man* arr, int& n) {
	print_dbase(arr, n);
	cout << "Выберите индекс сотрудника, которого вы хотите удалить\n";
	int k;
	cin >> k;
	--k;
	for (int i = k; i < n; ++i) {
		arr[i] = arr[i + 1];
	}
	--n;
}

//-----------------------------Поиск сотрудника в списке по фамилии
int find(Man* arr, int n, char* name) //возвращает индес элемента с данными о 
//сотруднике в БД,реализованной в виде массива
{
	int ind = -1;
	for (int i = 0; i < n; i++)
		if (!strcmp(arr[i].getName(), name))
		{
			cout << arr[i].getName() << setw(20 - strlen(arr[i].getName()) + 6)
				<< arr[i].getBirthYear() << setw(10) << arr[i].getPay() << endl;
			ind = i;
		}
	return ind;
}
//------- Поиск и вывод более старших по возрасту сотрудников
int find(Man* arr, int n, int birth_year)
{
	int ind = -1;
	for (int i = 0; i < n; i++)
		if (arr[i].getBirthYear() < birth_year)
		{
			ind = i;
			cout << arr[i].getName() << setw(20 - strlen(arr[i].getName()) + 6)
				<< arr[i].getBirthYear() << setw(10) << arr[i].getPay() << endl;
		}
	return ind;
}
//-------- Поиск и вывод сотрудников с окладом, большим чем "pay"
int find(Man* arr, int n, float pay)
{
	int ind = -1;
	for (int i = 0; i < n; i++)
		if (arr[i].getPay() > pay)
		{
			ind = i;
			cout << arr[i].getName() << setw(20 - strlen(arr[i].getName()) + 6)
				<< arr[i].getBirthYear() << setw(10) << arr[i].getPay() << endl;
		}
	return ind;
}
//--------------------------------------
int menu_f()
{
	cout << "\n----------------- ПОИСК -----------------\n";
	cout << "1 - поиск по фамилии	 2 - по году рождения\n"
		<< "3 - по окладу		 4 - конец поиска\n ";
	cout << "Для выбора операции введите число от 1 до 4\n";
	int resp;
	cin >> resp;
	cin.clear();
	cin.ignore(10, '\n');
	return resp;
}
//-------------------------------------	 Поиск
void find_man(Man* arr, int n)
{
	char buf[l_name];
	int birth_year;
	float pay;

	while (true)
	{
		switch (menu_f())
		{
		case 1: cout << "Введите фамилию сотрудника\n";
			cin >> buf;
			if (find(arr, n, buf) < 0)
				cout << "Сотрудника с фамилией " << buf << " в списке нет\n";
			break;
		case 2: cout << "Введите год рождения" << endl;
			cin >> birth_year;
			if (find(arr, n, birth_year) < 0)
				cout << "В списке нет сотрудников, родившихся до "
				<< birth_year << " года\n";
			break;
		case 3: cout << "Введите оклад" << endl;
			cin >> pay;
			if (find(arr, n, pay) < 0)
				cout << "В списке нет сотрудников с окладом, большим "
				<< pay << " руб.\n";
			break;
		case 4: return;
		default:
			cout << "Неверный ввод\n";
		}

	}
}
