#include "Polynomial/Polynomial.h"
#include <cstring> // strcmp on linux lol


void termDemo() {
    Term t1(3);
    cout << "3x^0 = " << t1 << endl;

    t1.power = 1;
    cout << "3x^1 = " << t1 << endl;

    t1.k = 1;
    t1.power = 3;
    cout << "1x^3 = " << t1 << endl;

    t1.k = -3;
    t1.power = 2;
    cout << "-3x^2 = " << t1 << endl;

    Term t2;
    cout << "Initialization without args = " << t2 << endl;
    t2.k = 6;
    t2.power = 2;
    cout << "-3x^2 + 6x^2 = " << t2 + t1 << endl;
}

void termInter() {
    Term t1;
    cout << "Enter term #1\n";
    cin >> t1;

    Term t2;
    cout << "Enter term #2\n";
    cin >> t2;
    cout << "Their sum = " << t1 + t2 << endl;
}


void polyDemo() {
    cout << "5x^5 - 4x^3 + 1x^2 + 0x^1 - 7x^0\n";
    Polynomial p(Term(5, 5));
    p += Term(-7);
    p += Term(0, 1);
    p += Term(-4, 3);
    p += Term(1, 2);

    cout << "Reverse order: ";
    p.setOrder(true);
    cout << p << endl;

    Polynomial p2(Term(3, 2));
    p2 += Term(-1, 1);
    cout << "Полином #1: " << p << endl;
    cout << "Полином #2: " << p2 << endl;
    cout << "Их произведение: " << p * p2 << endl;
    cout << "Их сумма: " << p + p2 << endl;

}

void polyInter() {
    cout << "Введите количество членов #1 полинома\n";
    int ans;
    cin >> ans;
    cin.ignore();  // Ignore the \n left by cin >> for getline
    Polynomial p1;
    for (int i = 0; i < ans; ++i) {
        Term t;
        cout << "Введите слагаемое\n";
        cin >> t;
        p1 += t;
    }

    Polynomial p2;
    cout << "Введите количество членов #2 полинома\n";
    cin >> ans;
    cin.ignore();
    for (int i = 0; i < ans; ++i) {
        Term t;
        cout << "Введите слагаемое\n";
        cin >> t;
        p2 += t;
    }

    cout << "Введите порядок, в котором следует выводить данные полиномы (0 -- прямой, 1 -- обратный)\n";
    bool order;
    cin >> order;
    p1.setOrder(order);
    p2.setOrder(order);

    cout << "Полином #1: " << p1 << endl;
    cout << "Полином #2: " << p2 << endl;
    cout << "Их произведение: " << p1 * p2 << endl;
    cout << "Их сумма: " << p1 + p2 << endl;
}

int demo() {
    termDemo();
    polyDemo();
    return 0;
}

int interactive() {
    termInter();
    polyInter();
    return 0;
}


int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");

    if ((argc == 2) && strcmp(argv[1], "i") == 0)  // Interactive
        return interactive();
    return demo();
}
