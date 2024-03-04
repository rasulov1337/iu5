#include <iostream>
#include "string/string.h"

using namespace std;
using namespace not_std;



int interactive() {
    String a, b;

    char buff[256];
    cout << "¬ведите первую строку\n";
    cin >> buff;
    a = buff;

    cout << "¬ведите вторую строку\n";
    cin >> buff;
    b = buff;

    cout << "–езультат сложени€ этих строк : " << a + b << endl;
    return 0;
}

int demo() {
    String a;
    a = "Hello world!";
    cout << a.c_str << endl;
    String b;
    b = "I've create dumb string realization\n";
    cout << b.c_str << endl;

    a = "Toyota Supra";
    b = " 2JZ GTE";

    String c;
    c = a + b;
    cout << c.c_str;
    return 0;
}


int main(int argc, char* argv[]) {
    setlocale(0, "");
    if ((argc == 2) && strcmp(argv[1], "i") == 0)  // Interactive
        return interactive();
    return demo();
}