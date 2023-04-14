#include <iostream>
#include <cstring>
#include "Ships/Corvette.h"
#include "Ships/Parusnik.h"

Ship** Ship::array = new Ship*[5];
int Ship::array_size = 0;
int Ship::max_array_size = 5;

using std::cin;

int demo() {
    Steamer steamer("Lekia", "Just a dummy steamer", 1000, 30);
    steamer.add();

    Corvette corvette("RU", "Hoonigan", 2000, 100, 555, false);
    corvette.add();

    Parusnik parusnik("LZ", "Ragh", 1300);
    parusnik.add();

    Ship::print();

    return 0;
}

int interactive() {
    char country[512] = "";
    char name[512] = "";
    int weight;
    int max_speed;
    
    cout << "Введите имя парохода\n";
    cin.getline(name, 512);
    cout << "Введите страну парохода\n";
    cin.getline(country, 512);
    cout << "Введите его вес\n";
    cin >> weight;
    cout << "Введите его макс скорость\n";
    cin >> max_speed;

    Steamer steamer(name, country, weight, max_speed);
    steamer.set_speed(20);
    steamer.turn_on_the_engine();
    steamer.add();

    Ship::print();

    return 0;
}



int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    if ((argc == 2) && strcmp(argv[1], "i") == 0)
        return interactive();
    return demo();
}
