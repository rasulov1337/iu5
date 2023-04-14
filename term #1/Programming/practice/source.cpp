#include "header.h"


int menu() {
    cout << "\n\nВыберите действие\n"
        "1) Вывести рейсы\n"
        "2) Добавить рейс\n"
        "3) Изменить рейс\n"
        "4) Удалить рейс\n"
        "5) Найти рейс по времени\n"
        "6) Выйти из программы\n"
        "Ваш выбор: ";
    return getInputInt();
}

void printFlights(vector<Flight>& flights, bool withNumeration) {
    if (flights.size() == 0) {
        cout << "Пока никаких рейсов нет!\n\n";
        return;
    }

    int columnsSize[3] = { 13, 19, 15 };
    int fromTextLen, toTextLen;
    for (int i = 0; i < flights.size(); ++i) {
        fromTextLen = flights[i].from.length();
        toTextLen = flights[i].to.length();
        if (fromTextLen > columnsSize[1])
            columnsSize[1] = fromTextLen;
        if (toTextLen > columnsSize[2])
            columnsSize[2] = toTextLen;
    }

    int numOfSpaceBeforeNumber = to_string(flights.size()).size();

    int tableWidth = columnsSize[0] + columnsSize[1] + columnsSize[2];

    if (withNumeration)
        cout << setw(numOfSpaceBeforeNumber) << left << '№' << ' ';
    cout << setw(columnsSize[0]) << left << "ВРЕМЯ ВЫЛЕТА" << ' ' 
        << setw(columnsSize[1]) << left << "ПУНКТ ОТПРАВЛЕНИЯ " << ' '
        << setw(columnsSize[2]) << left << "ПУНКТ ПРИБЫТИЯ" << endl;

    for (int i = 0; i < flights.size(); ++i) {
        if (withNumeration)
            cout << setw(numOfSpaceBeforeNumber) << left << i + 1 << ' ';
        cout << setw(columnsSize[0]) << left << flights[i].departureTime << ' '
            << setw(columnsSize[1]) << left << flights[i].from << ' '
            << setw(columnsSize[2]) << left << flights[i].to << endl;
    }
    cout << endl;
}

void addFlight(vector<Flight>& flights) {
    Flight f;
    cout << "Введите, пожалуйста, пункт отправления рейса.\n";
    f.from = getInputText();
    cout << "Введите, пожалуйста, пункт назначения рейса.\n";
    f.to = getInputText();
    f.departureTime = getTimeAsString();

    for (int i = 0; i < flights.size(); ++i) {
        if (f.departureTime == flights[i].departureTime) {
            cout << "Ошибка! Рейс в такое время уже есть!\n\n";
            return;
        }
    }

    int i = 0; // Index where we insert new elem
    for (; i < flights.size(); ++i) {
        if (f.departureTime < flights[i].departureTime) {
            break;
        }
    }

    flights.insert(flights.begin() + i, f);
}

void deleteFlight(vector<Flight>& flights) {
    if (flights.size() == 0) {
        cout << "Пока рейсов нет! Поэтому ничего нельзя удалить\n";
        return;
    }
    printFlights(flights, true);
    cout << "Выберите номер рейса, который вы хотите удалить (от 1 до " << flights.size() << "): ";
    int n = getInputInt();
    while (n < 1 || n > flights.size()) {
        cout << "Вы ввели неправильный номер рейса. Пожалуйста, повторите ввод\n";
        n = getInputInt();
    }
    flights.erase(flights.begin() + n - 1);
    cout << "Авиарейс был успешно удален.\n";
}

void editFlight(vector<Flight>& flights) {
    if (flights.size() == 0) {
        cout << "Пока рейсов нет! Поэтому ничего нельзя изменить\n";
        return;
    }
    printFlights(flights, true);
    cout << "Выберите номер рейса, который вы хотите изменить (от 1 до " << flights.size() << "): ";
    int n = getInputInt();
    while (n < 1 || n > flights.size()) {
        cout << "Вы ввели неправильный номер рейса. Пожалуйста, повторите ввод\n";
        n = getInputInt();
    }
    --n;
    flights.erase(flights.begin() + n);
    cout << "Введите, пожалуйста, новые данные о рейсе\n\n";
    addFlight(flights);
    cout << "Авиарейс был успешно изменен.\n";
}

void searchFlight(vector<Flight>& flights) {
    cout << "Поиск авиарейса по времени:\n";
    string neededTime = getTimeAsString();

    // Бинарный поиск
    int l = 0, r = flights.size() - 1, mid;
    string midTime;
    while (l <= r) {
        mid = (l + r) / 2;
        midTime = flights[mid].departureTime;
        if (midTime == neededTime) {
            cout << "Рейс найден!\n";

            cout << "ВРЕМЯ ВЫЛЕТА: " << midTime
                << "\nПУНКТ ОТПРАВЛЕНИЯ: " << flights[mid].from 
                << "\nПУНКТ ПРИБЫТИЯ: " << flights[mid].to << endl;
            return;
        }
        if (midTime < neededTime)
            l = mid + 1;
        else
            r = mid - 1;

    }
    cout << "Авиарейс с таким временем не найден!\n";
}


string trim(string str) {
    int a = 0;
    for (; a < str.length(); ++a) {
        if (!iswspace(str[a]))
            break;
    }

    int b = str.length() - 1;
    for (; b > 0; --b) {
        if (!iswspace(str[b]))
            break;
    }
    return str.substr(a, b - a + 1);
}

string getTimeAsString() {
    cout << "Введите, пожалуйста, время вылета авиарейса. Сначала часы\n";
    int hh = getInputInt();

    while (hh < 0 || hh > 23) {
        cout << "Вы ввели некорректное время (часы). Повторите ввод, пожалуйста:\n";
        hh = getInputInt();
    }

    cout << "Введите, пожалуйста, время вылета авиарейса. Теперь минуты\n";
    int mm = getInputInt();
    while (mm > 59 || mm < 0) {
        cout << "Вы ввели некорректное время (минуты). Повторите, пожалуйста, ввод:\n";
        mm = getInputInt();
    }
    string hh_str = to_string(hh);
    string mm_str = to_string(mm);

    if (hh < 10)
        hh_str = '0' + hh_str;
    if (mm < 10)
        mm_str = '0' + mm_str;

    return hh_str + ':' + mm_str;
}

int getInputInt() {
    string input;
    getline(cin, input);
    input = trim(input);

    while (input.empty() || input.find_first_not_of("1234567890") != string::npos) {
        cout << "Некорректный ввод. Вводите, пожалуйста, только неотрицательные числа\n";
        getline(cin, input);
        input = trim(input);
    }
    return stoi(input);
}

string getInputText() {
    string res;
    getline(cin, res);
    res = trim(res);
    while (res.empty() || res.find_first_not_of("abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "абвгдеёжзийклмнопрстуфхцчшщъыьэюя"
        "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ -") != string::npos){
        cout << "Неверный ввод. Повторите ввод: ";
        getline(cin, res);
        res = trim(res);
    }
    return res;
}


void saveData(vector<Flight>& flights) {
    if (flights.size() == 0) {
        remove(DATA_FILENAME);
        return;
    }

    ofstream f(DATA_FILENAME);
    for (int i = 0; i < flights.size(); ++i) {
        f << flights[i].departureTime << ";" << flights[i].from << ';' << flights[i].to;
        if (i != flights.size() - 1)
            f << endl;
    }
    f.close();
    cout << "Данные успешно записаны на диск\n";
}

void loadData(vector<Flight>& flights) {
    ifstream f(DATA_FILENAME);
    if (!f)
        return;

    Flight flight;
    while (!f.eof()) {
        getline(f, flight.departureTime, ';');
        getline(f, flight.from, ';');
        getline(f, flight.to);
        flights.push_back(flight);
    }
    f.close();
}

