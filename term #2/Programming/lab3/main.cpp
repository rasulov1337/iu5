#include <iostream>
#include <iomanip>
#include "Fraction/Fraction.h"


int demo() {
    setlocale(LC_ALL, "Russian");

    // ввод дроби с клавиатуры
    cout << "Введите дробь: \n";
    Fraction z("5/1");
    cin >> z;
    cout << "z=" << z << endl;
    // проверка конструкторов
    Fraction fr1(10, 14), fr2;
    cout << "fr2=" << fr2 << endl;
    cout << "fr1=" << fr1 << endl;
    Fraction fr = Fraction("-1 4/8");  // Из-за explicit пришлось сделать так вместо Fraction fr = "-1 4/8"
    cout << "fr=" << fr << endl;
    Fraction x(z), y;
    cout << "x=" << x << endl;
    double dbl = -1.25;
    Fraction f = Fraction(dbl);
    cout << "f=" << f << endl;
    // проверка перегруженной операции "+"
    cout << "Checking +\n";
    y = x + z;
    cout << "y=" << y << endl;
    y += x;
    f += dbl / 2;
    cout << "f=" << f << endl;
    y = x + dbl;
    cout << "y=" << y << endl;
    y = dbl + y;
    cout << "y=" << y << endl;
    y += dbl;
    cout << "y=" << y << endl;
    int i = 5;
    y += i;
    cout << "y=" << y << endl;
    y = i + x;
    cout << "y=" << y << endl;
    y = x + i;
    cout << "y=" << y << endl;
    y += dbl + i + x;
    cout << "y=" << y << endl;
    return 0;
}


int interactive() {
    while (true) {
        double a;
        Fraction b;
        cout << "Введите double\n";
        cin >>a;
        cout << "Введите дробь\n";
        cin >> b;
        cout << "Их сумма: " << a + b << endl;

        int k;
        cout << "Введите int\n";
        cin >> k;
        cout << "Введите дробь\n";
        cin >> b;
        cout << "Их сумма: " << a + b << endl;

        Fraction c;
        cout << "Введите 1 дробь\n";
        cin >> c;
        cout << "Введите 2 дробь\n";
        cin >> b;
        cout << "Их сумма: " << c + b << endl;
        
    }
}

int main(int argc, char *argv[]) {
    bool isInteractive = false;    // по умолчанию демо-режим.

    // Если i передается в качестве аргумента, то программу
    // необходимо запустить в интерактивном режиме
    if ((argc == 2) && strcmp(argv[1], "i") == 0) {
        isInteractive = true;
    }

    if (isInteractive) {
        return interactive();

    } else {
        return demo();
    }
}