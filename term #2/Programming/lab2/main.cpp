#include <iostream>
#include "planet/funcs.h"
#include "subscriber/interactive.cpp"

using namespace std;

int demo()
{
	char filename[] = "sunsys.txt";
	Planet planets[MAX_PLANET_SIZE];
	int n_planet = 0;

	cout << "Чтение БД из файла...\n";
	n_planet = read_db(filename, planets);
	cout << "Вывод БД\n";
	print_db(planets, n_planet);

	cout << "Добавляю новую планету Lekia\n";
	add(planets, n_planet, "Lekia", 1000000, 1, 3);
	print_db(planets, n_planet);

	cout << "Ищу в списке планету Mars и меняю ее название на Twix\n";
	int ind;
	if ((ind = find(planets, n_planet, "Mars")) >= 0)
		planets[ind].edit("Twix", 1000, false, 100);
	else
		cout << "Такой планеты нет" << endl;
	print_db(planets, n_planet);

	cout << "Сортирую БД\n";
	sort_db(planets, n_planet);
	print_db(planets, n_planet);

	cout << "Удаляю планету Pluto\n";
	del(planets, n_planet, "Pluto");
	print_db(planets, n_planet);

	cout << "Записываю изменения на диск\n";
	write_db(filename, planets, n_planet);

	cout << "Завершение программы...\n";
	return 0;
}

int interactive()
{
	char filename[] = "subs.txt";
	Subscriber subs[MAX_SUBS_NUM];
	int n = 0;
	int ind;
	while (true) {
		switch (menu())
		{
		case 1:
			n = read_db(filename, subs);
			break;
		case 2:
			write_db(filename, subs, n);
			break;
		case 3:
			add(subs, n);
			break;
		case 4:
			if ((ind = find(subs, n)) >= 0)
				subs[ind].edit();
			else
				cout << "Такой планеты нет" << endl;
			break;
		case 5:
			print_db(subs, n);
			break;
		case 6:
			sort_db(subs, n);
			break;
		case 7:
			del(subs, n);
			break;
		case 8:
			return 0;
		default:
			cout << " Неправильный ввод" << endl;
			break;
		}
	}
	return 0;
}

int main(int argc, char* argv[]) {
    setlocale(0, "");
    if ((argc == 2) && strcmp(argv[1], "i") == 0)  // Interactive
        return interactive();
    return demo();
}
