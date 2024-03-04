#include "header.h"

int main() {
	system("chcp 1251");

	vector <Flight> flights;
	
	// load everything from disk...
	loadData(flights);

	
	bool running = true;
	while (running) {
		switch (menu()) {
		case 1:  // Вывести рейсы
			printFlights(flights);
			break;
		case 2:  // Добавить рейс
			addFlight(flights);
			cout << "Авиарейс был успешно добавлен\n";
			break;
		case 3:  // Изменить рейс
			editFlight(flights);
			break;
		case 4:  // Удалить рейс
			deleteFlight(flights);
			break;
		case 5: // Найти рейс
			searchFlight(flights);
			break;
		case 6: // Выйти из программы
		{ 
			cout << "Записать изменения в файл? (да -- 1, нет -- 0)\n";
			int ans = getInputInt();
			while (ans != 1 && ans != 0) {
				cout << "Пожалуйста, введите либо 0 (не сохранять данные), либо 1 (сохранить данные в файл)\n";
				ans = getInputInt();
			}
			if (ans)
				saveData(flights);
			else
				cout << "Выход без сохранения данных\n";
			running = false;
			break;
		}
		default:
			cout << "Пожалуйста введите цифру от 1 до 6.\n";
			break;
		}
	}
}