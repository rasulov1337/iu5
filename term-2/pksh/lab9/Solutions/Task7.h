﻿#include <list>
#include <iostream>
#include <iomanip>

using namespace std;

// Task #7
/* Создайте класс с именем Time, содержащий три закрытых поля типа int, предназначенные для хранения часов, минут и секунд.
(Подсказка: не забудьте для класса Time определить операторы < и ==).
Один из конструкторов класса должен инициализировать поля нулевыми значениями, а другой конструктор — заданным набором значений.
Создайте метод класса, который будет выводить значения полей на экран в формате 11:59:59.

Создать список объектов типа Time с помощью контейнера list в main() и сразу занести в него информацию о шести датах:
(1, 2, 63), (14, 57, 19), (7, 32, 20), (5, 13, 23), (10, 19, 45), (19, 9, 59).
Вывести список на экран таким образом, чтобы каждая дата выводились в отдельной строке.
Создайте новый список, в который запишите даты первого списка, которые относятся к ночи (с 0 до 5 часов).
Выведите на экран второй список. Напишите функцию вывода списка на экран.
*/

class Time {
public:
	explicit Time();
	explicit Time(int hh, int mm, int ss);

	bool operator < (const Time& t) const;

	bool operator == (const Time& t) const;

	void print() const;
private:
	int hh, mm, ss;
};

void printTime(const list<Time>& q);

void task7();
