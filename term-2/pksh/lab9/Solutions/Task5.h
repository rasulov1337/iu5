﻿#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


// Task 5
/* Создайте класс с именем Date, содержащий три закрытых поля типа int, предназначенные для хранения дня, месяца и года.
(Подсказка: не забудьте для класса Date определить операторы < и ==).
Один из конструкторов класса должен инициализировать поля датой 01.01.1970, а другой конструктор — заданным набором значений.
Создайте метод класса, который будет выводить значения полей на экран в формате 11.05.2019.

Создать массив объектов типа Date с помощью контейнера vector в main() и сразу занести в него информацию о шести датах:
(1, 2, 1963), (14, 7, 1995), (7, 12, 2088), (5, 3, 2030), (24, 9, 2013), (19, 9, 2020).
Вывести массив на экран таким образом, чтобы каждая дата выводились в отдельной строке.
Создайте новый вектор, в который запишите даты первого вектора, которые относятся к будущему.
Выведите на экран второй вектор. Напишите функцию вывода массива на экран.*/
class Date {
public:
	Date();
	Date(int dd, int mm, int yy);
	
	void print() const;

	bool operator<(const Date& other);
	bool operator==(const Date& other);

private:
	int dd;
	int mm;
	int yy;
};

void printVector(const vector<Date>& v);

void task5();